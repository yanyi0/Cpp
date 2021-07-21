//
//  main.cpp
//  015-构造函数
//
//  Created by Cloud on 2021/7/19.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Car {
    int m_price;
    Car(){
        cout << "Car::car()" << endl;
    }
    void run(){
        cout << "Car::run " << m_price << endl;
    }
};

struct Teacher {
    int m_age;
//    Teacher(){
//        cout << "Teacher()" << endl;
//    }
};
struct Person {
    int m_age;
    
    Person(){
        m_age = 0;
        cout << "Person()" << endl;
    }
    
    Person(int age){
        m_age = age;
        cout << "Person(int age)" << endl;
    }
    void display(){
        cout << m_age << endl;
    }
};
Person g_person0;//Person()
Person g_person1();//函数声明
Person g_person2(20);//Person(int age)
int main(){
    Person person0;//Person()
    Person person1();//函数声明
    Person person2(20);//Person(int age)
    
    Person *p0 = new Person;//Person()
    Person *p1 = new Person();//Person()
    Person *p2 = new Person(20);//Person(int age)
    /*
    Teacher teacher;
    teacher.m_age = 10;
     */
    /*
    Car car;//调用构造函数
    Car *c = new Car;//调用构造函数
    delete c;
     
    Car * cc = (Car *)malloc(sizeof(Car));//没有调用构造函数
    cc->m_price = 10;
    cc->run();
    */
    
    /*
    Person person1;
    person1.display();
    Person person2(20);
    person2.display();
    Person person3(30);
    person3.display();
     */
    getchar();
    return 0;
}

