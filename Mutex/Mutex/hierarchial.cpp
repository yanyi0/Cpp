//
//  hierarchial_mutex.cpp
//  Mutex
//
//  Created by Cloud on 2021/12/25.
//

#include <stdio.h>
#include "hierarchical_mutex.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>
 
hierarchical_mutex high_mutex(1000);
hierarchical_mutex low_mutex(500);
void low_handle();
void high_handle() {
    std::lock_guard<hierarchical_mutex> lock(high_mutex);
    std::this_thread::sleep_for(std::chrono::microseconds(2000));
    std::cout << "高层次锁任务执行完毕！！" << std::endl;
    low_handle();
}
void thread_a() {
    high_handle();
}
 
void low_handle() {
    std::lock_guard<hierarchical_mutex> lock(low_mutex);
    std::this_thread::sleep_for(std::chrono::microseconds(1500));
    std::cout << "低层次锁任务执行完毕！！" << std::endl;
}
void thread_b() {
    hierarchical_mutex now_mutex(100);
    std::lock_guard<hierarchical_mutex> now_lock(now_mutex);
 
    high_handle();
}
 
int main()
{
    std::thread a(thread_a);
    std::thread b(thread_b);
    a.join();
    b.join();
}
