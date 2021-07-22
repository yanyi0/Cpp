//
//  main.cpp
//  024-构造函数的互相调用
//
//  Created by Cloud on 2021/7/21.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Person {
    int m_age;
    int m_height;
    Person(){
        //创建了一个临时的person对象
        Person(10,20);
//        Person person;
//        person.m_age = 10;
//        person.m_height = 20;
    }
    Person(int age,int height){
        m_age = age;
        m_height = height;
    }
};
int main(){
    Person person;
    cout << person.m_age << endl;
    cout << person.m_height << endl;
    return 0;
}
