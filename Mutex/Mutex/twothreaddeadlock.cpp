//
//  twothreaddeadlock.cpp
//  Mutex
//
//  Created by Cloud on 2021/12/25.
//

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>
using namespace std;

class LogFile {
public:
    LogFile() {
        f.open("log.txt");
    }
    ~LogFile() {
        f.close();
    }
    void shared_print(string msg, int id) {
//        std::lock_guard<std::mutex> guard(_mu);
//        std::lock_guard<std::mutex> guard2(_mu2);
        if(&_mu < &_mu2){
            _mu.lock();
            _mu2.unlock();
        }
        else {
            _mu2.lock();
            _mu.lock();
        }
        f << msg << id << endl;
        cout << msg << id << endl;
    }
    void shared_print2(string msg, int id) {
//        std::lock_guard<std::mutex> guard(_mu2);
//        std::lock_guard<std::mutex> guard2(_mu);
        if(&_mu < &_mu2){
            _mu.lock();
            _mu2.unlock();
        }
        else {
            _mu2.lock();
            _mu.lock();
        }
        f << msg << id << endl;
        cout << msg << id << endl;
    }
    
private:
    std::mutex _mu;
    std::mutex _mu2;
    ofstream f;
};

void function_1(LogFile& log) {
    for(int i=0; i>-100; i--)
        log.shared_print2(string("From t1: "), i);
}

int main()
{
    LogFile log;
    std::thread t1(function_1, std::ref(log));

    for(int i=0; i<100; i++)
        log.shared_print(string("From main: "), i);

    t1.join();
    return 0;
}

