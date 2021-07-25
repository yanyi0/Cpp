//
//  main.cpp
//  038-const成员
//
//  Created by Cloud on 2021/7/26.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car{
public:
    const int m_price = 0;
    Car():m_price(0){};
    void run() const{
        cout << "run() const" << endl;
//        test();//报错
    }
    
//    void run(){
//        cout << "run()" << endl;
//    }
    void test(){
        run();//可以调用
    }
    static void accelerate(){
        cout << "accelerate()" << endl;
    }
};
int main(){
    Car car;
    car.run();
    
    const Car car2;
    car2.run();//报错，不能调用
    car2.accelerate();
    
    getchar();
    return 0;
}
