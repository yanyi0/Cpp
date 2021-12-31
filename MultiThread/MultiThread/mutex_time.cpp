//
//  mutex_time.cpp
//  MultiThread
//
//  Created by Cloud on 2021/12/30.
//

#include <stdio.h>
#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>
using namespace std;

std::chrono::milliseconds inteval(100);
std::timed_mutex tmutex;

int job_shared = 0;//两个线程都能修改'job_shared',mutex将保护此变量
int job_exclusive = 0; //只有一个线程能修改'job_exclusive',不需要保护

//此线程只能修改 'job_shared'
void job_1(){
    std::lock_guard<std::timed_mutex> lockg(tmutex);//获取RAII锁，离开作用域会自动析构解锁
    std::this_thread::sleep_for(5*inteval);//令‘job_1’封锁等待
    ++job_shared;
    std::cout << "job_1 shared (" << job_shared << ")\n";
}
//此线程能修改‘job_shared’ 和 ‘job_exclusive’
void job_2(){
    while (true) {//无线循环只要能获得锁并修改“job_shared”
        std::unique_lock<std::timed_mutex> ulock(tmutex,std::defer_lock);//创建一个智能锁但先不锁定
        //尝试获得锁成功则修改“job_shared”
        if (ulock.try_lock_for(3 * inteval)) {
            ++job_shared;
            std::cout << "job_2 shared (" << job_shared << ")\n";
            return;
        }else{//尝试获得锁失败，接着修改“job_exclusive”
            ++job_exclusive;
            std::cout << "job_2 exclusive (" << job_shared << ")\n";
            std::this_thread::sleep_for(inteval);
        }
        
    }
}
int main(){
    std::thread t1(job_1);
    std::thread t2(job_2);
    t1.join();
    t2.join();
    getchar();
    return 0;
}


