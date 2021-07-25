//
//  main.cpp
//  034-菱形继承
//
//  Created by Cloud on 2021/7/23.
//

#include "main.hpp"
#include <iostream>
using namespace std;
//不用虚继承Undergraduate的大小 10 * 4 + 4 + 10 *4 +4 + 4 = 92
//使用虚继承 8 + 4 + 8 + 4 + 4 + 10* 4 = 68(8字节对齐) = 72
struct Person {
    int m_age = 1;
//    int m_age1= 2;
//    int m_age2= 3;
//    int m_age3= 4;
//    int m_age4= 5;
//    int m_age5= 6;
//    int m_age6= 7;
//    int m_age7= 8;
//    int m_age8= 9;
//    int m_age9= 10;
};
struct Student:virtual Person{
    int m_score = 2;

};
struct Worker:virtual Person{
    int m_salary = 3;
};
struct Undergraduate:Student,Worker{
    int m_grade = 4;
};
//    cout << sizeof(Undergraduate) << endl;
int main(){

    Undergraduate ug;
    ug.m_age = 5;
    ug.m_score = 6;
    ug.m_salary = 7;
    ug.m_grade = 8;
//    ug.m_age = 10;
//    cout << ug.m_age << endl;
    //ug.m_age = 10;//二义性，分不清哪个m_age
    return 0;
}
