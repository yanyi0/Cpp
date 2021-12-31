//
//  global_variable.cpp
//  MultiThread
//
//  Created by Cloud on 2021/12/30.
//

#include <stdio.h>
#include <vector>
#include <numeric>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sys/types.h>
#include <unistd.h>

int res = 0; //保存结果的全局变量
std::mutex mu; //互斥锁全局变量
std::condition_variable cond;//全局条件变量
void accumulate(std::vector<int>::iterator first,std::vector<int>::iterator last){
    int sum = std::accumulate(first, last, 0);//标准库求和函数
    std::cout << sum << std::endl;
    std::unique_lock<std::mutex> locker(mu);
    std::cout << "执行了" <<  res << "次" << std::endl;
    res = sum;
    locker.unlock();
    cond.notify_one();//向一个等待线程发出条件已满足通知
}
int main(){
    //pid 打印
    std::cout << "pid= " << getpid() << std::endl;
     
    //tid打印
    std::thread::id tid = std::this_thread::get_id(); // 获取本线程的id
    std::cout << "this thread id = " << tid << std::endl;
    std::vector<int> numbers = {1,2,3,4,5,6};
    std::thread work_thread(accumulate,numbers.begin(),numbers.end());
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker,[](){return res;});//如果条件变量被唤醒，检查结果是否被改变，为真则直接返回，为假则继续等待
    std::cout << "wait被卡住" << std::endl;
    std::cout << "result=" << res << "\n";
    locker.unlock();
    work_thread.join();
    
    getchar();
    return 0;
}
