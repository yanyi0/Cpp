//
//  main.cpp
//  049-调用父类拷贝构造函数
//
//  Created by Cloud on 2021/9/28.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person{
public:
    int m_age;
    Person(int age = 0):m_age(age){
        cout << "Person(int age = 0)" << age << endl;
    }
//    Person(const Person &person):m_age(person.m_age){
//        cout << "Person(const Person &person):m_age(person.m_age)"<< person.m_age << endl;
//    }
};
class Student:public Person{
public:
    int m_score;
    Student(int age=0,int score=0):Person(age),m_score(score){
        cout << "Student(int age=0,int score=0) age:"<< age << " score:"<< score << endl;
    }
//    Student(const Student &student):Person(student),m_score(student.m_score){
//        cout << "Student(const Student &student)"<< m_score << endl;
//    }
};
int main(){
    Student stu1(18,100);
    Student stu2(stu1);
    cout << stu2.m_age << endl;
    cout << stu2.m_score << endl;
    getchar();
    return 0;
}
