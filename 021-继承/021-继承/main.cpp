//
//  main.cpp
//  021-继承
//
//  Created by Cloud on 2021/7/20.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Person {
    int m_age;
    void run(){};
};
struct Student:Person{
    int m_score;
    void study(){};
};

struct Worker:Person{
    int m_salary;
    void work(){};
};

int main(){
    return 0;
}
