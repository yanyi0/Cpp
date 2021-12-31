//
//  main.cpp
//  MultiThread
//
//  Created by Cloud on 2021/12/29.
//

#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
using namespace std;

static std::mutex mtx;

static std::deque<int> dq;

static int productNum = 5;

void Producer(){
    using namespace std::literals::chrono_literals;
    for (int i=1; i <= productNum; ++i) {
        mtx.lock();
        dq.push_front(i);
        cout << "Producer 生产产品为: " << i << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(1s);
    }
}
void Consumer(){
    while(true){
        if(dq.empty()){
            continue;
        }
        mtx.lock();
        int data = dq.back();
        dq.pop_back();
        std::cout << "Consumer 消费产品为: " << data << std::endl;
        mtx.unlock();
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
