//
//  main.cpp
//  036-static成员
//
//  Created by Cloud on 2021/7/25.
//

#include "main.hpp"
#include <iostream>
using namespace std;
/*
class Car{
private:
    int m_age;
public:
    static int m_price;
    static void run(){
        cout << "run()" << endl;
//        m_age = 1;//不能访问
//        test();//不能访问
    }
    void test(){
        run();
        m_price = 10;
        m_age = 0;
        run();
    }
};
*/
//静态成员变量必须初始化，且只能在类的外部初始化
//int Car::m_price = 0;
class Person{
public:
    static int m_age;
    
};
int Person::m_age = 0;
class Student:Person{
public:
    static int m_age;
};
int Student::m_age = 0;
class Car {
private:
    //严格来说这里需要考虑多线程安全问题
    static int ms_count;
public:
    Car(){
        cout << "Car()" << endl;
        ms_count ++;
    }
    ~Car(){
        cout << "~Car()" << endl;
        ms_count --;
    }
    static int getCount(){
        return ms_count;
    }
};
int Car::ms_count = 0;
Car c;
int main(){
    Car car;
    Car *ca = new Car();
    cout << Car::getCount() << endl;
    
    /*
    cout << &Person::m_age << endl;
    cout << &Student::m_age << endl;
    */
    
    /*
    Car ca;
    ca.run();
    Car *c = new Car();
    c->run();
    Car::run();
    
    Car car1;
    car1.m_price = 100;
    
    Car car2;
    car1.m_price = 200;
    
    Car car3;
    car1.m_price = 300;
    
    Car *car = new Car();
    car->m_price = 400;
    delete car;
    cout << Car::m_price << endl;
    */
    getchar();
    return 0;
}
