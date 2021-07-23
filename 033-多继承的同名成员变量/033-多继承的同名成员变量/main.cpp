//
//  main.cpp
//  033-多继承的同名成员变量
//
//  Created by Cloud on 2021/7/23.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Student{
    int m_age;

};
struct Worker{
    int m_age;
};
struct Undergraduate:Student,Worker{
    int m_age;
};
int main(){
    cout << sizeof(Undergraduate) << endl;
    Undergraduate ug;
    ug.m_age = 10;
    cout << ug.m_age << endl;
    ug.Student::m_age = 20;
    ug.Worker::m_age = 23;
    cout << ug.Student::m_age << endl;
    cout << ug.Worker::m_age << endl;
    
    return 0;
}
