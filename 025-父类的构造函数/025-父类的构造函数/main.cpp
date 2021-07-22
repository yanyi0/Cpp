//
//  main.cpp
//  025-父类的构造函数
//
//  Created by Cloud on 2021/7/21.
//

#include "main.hpp"
#include <iostream>
using namespace std;
//class Person{
//    int m_age;
//public:
//    Person(int age) :m_age(age){}
//};
//class Student:Person{
//    int m_no;
//public:
//    Student(int no,int age) :m_no(no),Person(age){
//        cout << "Student::Student()" << endl;
//    }
//};
struct Person {
    Person(){
        cout << "Person::Person()" << endl;
    };
    ~Person(){
        cout << "Person::~Person()" << endl;
    };
};
struct Student:Person{
    Student(){
        cout << "Student::Student()" << endl;
    };
    ~Student(){
        cout << "Student::~Student()" << endl;
    };
};
int main(){
    {
      Student student;
    }
    return 0;
}
