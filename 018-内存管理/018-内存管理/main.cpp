//
//  main.cpp
//  018-内存管理
//
//  Created by Cloud on 2021/7/20.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Car {
    int price;
    Car(){
        cout << "Car::Car()" << endl;
    }
    ~Car(){
        cout << "Car::~Car()" << endl;
    }
};
struct Person {
    int m_age;
    Car *car;
    //用来做初始化的工作
    Person(){
        m_age = 0;
        car = new Car;
        cout << "Person::Person()" << endl;
    }
    //用来做内存清理的工作
    ~Person(){
        delete car;
        cout << "Person::~Person()" << endl;
    }
};
int main(){
    //内存泄露:该释放的内存没有得到释放
    {
        Person person;
    }
    getchar();
    return 0;
}
