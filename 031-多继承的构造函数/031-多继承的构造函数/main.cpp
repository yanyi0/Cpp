//
//  main.cpp
//  031-多继承的构造函数
//
//  Created by Cloud on 2021/7/23.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Student{
    int m_score;
    Student(int score):m_score(score){}
    void study(){
        cout << "Student::study() - score = " << m_score << endl;
    }
};
struct Worker{
    int m_salary;
    Worker(int salary):m_salary(salary){}
    void work(){
        cout << "Worker::work() - salary = " << m_salary << endl;
    }
};
struct Undergraduate:Student,Worker{
    int m_grade;
    Undergraduate(int grade,int score,int salary):m_grade(grade),Student(score),Worker(salary){}
    void play(){
        cout << "Undergraduate::play() - m_grade = " << m_grade << endl;
    }
};
int main(){
    Undergraduate *u = new Undergraduate(4,100,2000);
    cout << u->m_grade << endl;
    cout << u->m_score << endl;
    cout << u->m_salary << endl;
//    u->m_score = 100;
//    u->m_salary = 2000;
//    u->m_grade = 4;
//    u->work();
//    u->study();
//    u->play();
    
    return 0;
}
