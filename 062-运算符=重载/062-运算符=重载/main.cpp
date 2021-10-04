//
//  main.cpp
//  062-运算符=重载
//
//  Created by Cloud on 2021/10/4.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person{
private:
    int m_age;
    int m_height;
    void operator=(const Person &person){}
public:
    Person(int age=0,int height=0):m_age(age),m_height(height){
        
    }
//    Person &operator=(const Person &person){
//        m_age = person.m_age;
//        return *this;;
//    }
    void display(){
        cout << "(" << m_age << "," << m_height << ")" << endl;
    }
};

int main(){
    Person p1(10,180);
    Person p2(15,175);
    (p1 = p2) = Person(50,20);
    p1.display();
    getchar();
    return 0;
}
