//
//  main.cpp
//  026-多态
//
//  Created by Cloud on 2021/7/21.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person {
public:
    int m_age;
};
class Student: public Person{
    int m_score;
};
void test(){
//    Person *p = new Student();
//    p->m_age = 10;//安全区域
//    Student *stu = (Student *)new Person();
//    stu->m_age = 10;
//    stu->m_score = 99;//不安全，实质上p指针指向的地址Person对象里面并不存在m_score的区域，p->m_score指向的是未知区域
}
struct Animal{
    virtual void speak(){
        cout << "Animal::speak()" << endl;
    }
    virtual void run(){
        cout << "Animal::run()" << endl;
    }
};
struct Dog:Animal{
    void speak(){
        cout << "Dog::speak()" << endl;
    }
    void run(){
        cout << "Dog::run()" << endl;
    }
};
struct Cat:Animal{
    void speak(){
        cout << "Cat::speak()" << endl;
    }
    void run(){
        cout << "Cat::run()" << endl;
    }
};
struct Pig:Animal{
    void speak(){
        cout << "Pig::speak()" << endl;
    }
    void run(){
        cout << "Pig::run()" << endl;
    }
};
void liu(Animal *p){
    p->speak();
    p->run();
}
int main(){
    test();
    
    liu(new Dog());
    liu(new Cat());
    liu(new Pig());
    
    Cat *p = (Cat *)new Dog();
    p->speak();//call Cat::speak
    p->run();//call Cat::run
    return 0;
}
