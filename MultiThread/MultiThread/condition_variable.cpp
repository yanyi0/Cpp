//
//  condition_variable.cpp
//  MultiThread
//
//  Created by Cloud on 2021/12/29.
//
#include <iostream>
#include <stdio.h>
#include <thread>
#include <deque>
#include <mutex>
#include <vector>
#include <condition_variable>
using namespace std;

std::mutex mtx;
std::condition_variable cv;
std::vector<int> vec;
int productNum = 5;

void Producer(){
    for (int i = 1; i <= productNum; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        while (!vec.empty()) {
            cv.wait(lock);//vec 不为空时阻塞当前线程
        }
        vec.push_back(i);
        std::cout << "Producer生产产品: " << i << std::endl;
        cv.notify_all();//释放线程锁
    }
}
void Consumer(){
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);//vec 为空时等待线程锁。其他线程锁释放时，当前线程继续执行
        while (vec.empty()) {
            cv.wait(lock);
        }
        int data = vec.back();
        vec.pop_back();
        std::cout << "Consumer消费产品: " << data << std::endl;
        cv.notify_all();
    }
}
int main(int argc, const char * argv[]) {
    std::thread t1(Producer);
    std::thread t2(Consumer);
    t2.join();
    t1.join();
    std::cin.get();
    return 0;
}
