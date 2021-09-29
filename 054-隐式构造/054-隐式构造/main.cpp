//
//  main.cpp
//  054-隐式构造
//
//  Created by Cloud on 2021/9/29.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person{
    int m_age;
    int m_height;
public:
    Person(){
        cout << "Person() - " << this << endl;
    }
    Person(int age,int height=0):m_age(age){
        cout << "Person(int) - " << this << endl;
    }
    Person(const Person &person){
        cout << "Person(const Person &person) - " << this << endl;
    }
    ~Person(){
        cout << "~Person() - " << this << endl;
    }
    void display(){
        cout << "display() - age is " << this->m_age << endl;
    }
};
void test(Person person){
    
}
Person test1(){
    return 40;
}

int main(){
    Person p1;
    p1 = 40;//p1 = Person(40);
//    test1();
//    test(30);
//    Person p1 = 20;
//    Person p2(20);
    getchar();
    return 0;
}
