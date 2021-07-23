//
//  main.cpp
//  030-多继承
//
//  Created by Cloud on 2021/7/23.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Student{
    int m_score;
    void study(){
        cout << "Student::study() - score = " << m_score << endl;
    }
};
struct Worker{
    int m_salary;
    void work(){
        cout << "Worker::work() - salary = " << m_salary << endl;
    }
};
struct Undergraduate:Student,Worker{
    int m_grade;
    void play(){
        cout << "Undergraduate::play() - m_grade = " << m_grade << endl;
    }
};
int main(){
    Undergraduate *u = new Undergraduate();
    u->m_score = 100;
    u->m_salary = 2000;
    u->m_grade = 4;
    u->work();
    u->study();
    u->play();
    
    return 0;
}
