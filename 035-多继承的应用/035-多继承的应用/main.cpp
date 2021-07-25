//
//  main.cpp
//  035-多继承的应用
//
//  Created by Cloud on 2021/7/25.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class JobBaomu{
public:
    virtual void clean() = 0;
    virtual void cook() = 0;
};
class JobTeacher{
public:
    virtual void playFootball() = 0;
    virtual void playBaseball() = 0;
};
class Student:public JobBaomu,public JobTeacher{
    int m_score;
public:
    void clean(){
        
    }
    void cook(){
        
    }
    void playFootball(){
        
    }
    void playBaseball(){
        
    }
};
class Worker:public JobTeacher{
    int m_salary;
public:
    void playFootball(){
        
    }
    void playBaseball(){
        
    }
};
int main(){
    /**
     兼职中心，招聘兼职，岗位如下:
     1.保姆:扫地、做饭
     2.老师:踢足球、打棒球
     应聘的角色如下:
     1.学生
     2.上班族
     3.护士
     4.医生
     5....
     */
    return 0;
}
