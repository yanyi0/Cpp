//
//  main.cpp
//  022-成员访问权限
//
//  Created by Cloud on 2021/7/20.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Person {
public:
    int m_age;
    Person(){
        m_age = 10;
    }
    void setAge(int age){
        m_age = age;
    }
    int getAge(){
        return m_age;
    }
};
struct Student:public Person{
    
};
struct GoodStudent:Student{
    void work(){
        setAge(10);
        getAge();
    }
};
int main(){
    Person *pp = new Person[3];
    cout << pp->m_age << endl;
    cout << pp[0].m_age << endl;
    cout << pp[1].m_age << endl;
    cout << pp[2].m_age << endl;
    cout << (*(pp+2)).m_age << endl;
    
    int a = 1;
    int b = 2;
    int c = 3;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    return 0;
}
