//
//  main.cpp
//  059-局部类
//
//  Created by Cloud on 2021/9/29.
//

#include "main.hpp"
#include <iostream>
using namespace std;
void test(){
    static int age = 10;
    //局部类
    class Car{
    public:
//        static int m_price;
        void run(){
            age = 11;
        }
    };
//    int Car::m_price = 10;
    Car car;
    car.run();
}
int main(){
    
    getchar();
    return 0;
}
