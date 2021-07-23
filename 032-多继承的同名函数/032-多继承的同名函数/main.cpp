//
//  main.cpp
//  032-多继承的同名函数
//
//  Created by Cloud on 2021/7/23.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Student{
    int m_score;
    void eat(){
        cout << "Student::eat()" << endl;
    }
};
struct Worker{
    int m_salary;
    void eat(){
        cout << "Worker::eat()" << endl;
    }
};
struct Undergraduate:Student,Worker{
    int m_grade;
    void eat(){
        cout << "Undergraduate::eat()" << endl;
    }
};
int main(){
    Undergraduate ug;
    ug.eat();
    ug.Student::eat();
    ug.Worker::eat();
    ug.Undergraduate::eat();
    
    return 0;
}
