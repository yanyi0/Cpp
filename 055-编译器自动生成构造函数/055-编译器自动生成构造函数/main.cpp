//
//  main.cpp
//  055-编译器自动生成构造函数
//
//  Created by Cloud on 2021/9/29.
//

#include "main.hpp"
#include <iostream>
using namespace std;

//很多教程都说:编译器会为每一个类都生成空的无参的构造函数 -----> 这句话是错的
//class Person{
//public:
//    int m_age = 5;
//    virtual void run(){
//
//    }
//};
//class Student:virtual public Person{
//public:
//    int m_score;
//};
//class Car {
//public:
//    int m_price;
//    Car(){
//
//    }
//};
//class Car {
//public:
//    int m_price = 0;
//};
//class Person {
//public:
//    Car car;
//};
class Person{
public:
    int m_age;
    Person(){
        
    }
};
class Student:public Person{
public:
    
};
int main(){
    Student student;
    getchar();
    return 0;
}
