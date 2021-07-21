//
//  main.cpp
//  023-初始化列表
//
//  Created by Cloud on 2021/7/21.
//

#include "main.hpp"
#include <iostream>
using namespace std;
int func(){return 8;}
int myAge(){
    cout << "myAge()" << endl;
    return 10;
};
int myHeight(){
    cout << "myHeight()" << endl;
    return 10;
};
struct Person {
    int m_age;
    int m_height;
    Person(int age = 1,int height = 125);
//    Person(int age,int height){
//        m_age = age;
//        m_height = height;
//    }
//    Person(int age,int height):m_age(func()),m_height(height+2){
//
//    };
//     Person(int age,int height):m_age(m_height),m_height(height+2){
//
//     };
//    Person(int age,int height):m_height(height+2),m_age(m_height){
//
//    };
//    Person(int age,int height):m_height(myHeight()),m_age(myAge()){
//
//    };

};
Person::Person(int age,int height):m_age(age),m_height(height){
    m_age = 10;
};
int main(){
    Person person;
    Person person0();//函数声明
    Person person1(17);
    Person person2(18,180);
    cout << person.m_age << endl;
    cout << person.m_height << endl;
    cout << person1.m_age << endl;
    cout << person1.m_height << endl;
    cout << person2.m_age << endl;
    cout << person2.m_height << endl;
    return 0;
}
