//
//  main.cpp
//  063-运算符重载注意
//
//  Created by Cloud on 2021/10/4.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person{
public:
    int m_age;
    Person &operator=(const Person &person){
        m_age = person.m_age;
        return *this;
    }
};
class Student:public Person{
public:
    int m_score;
    Student &operator=(const Student &student){
        Person::operator=(student);
        m_score = student.m_score;
        return *this;
    }
};
int main(){
    Student stu1;
    stu1.m_age = 10;
    stu1.m_score = 100;
    
    Student stu2;
    stu2 = stu1;
    
    getchar();
    return 0;
}
