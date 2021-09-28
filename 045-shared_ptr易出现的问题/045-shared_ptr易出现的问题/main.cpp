//
//  main.cpp
//  045-shared_ptr易出现的问题
//
//  Created by Cloud on 2021/9/7.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person {
    int m_age;
public:
    Person(){
        cout << "Person()" << endl;
    }
    Person(int age):m_age(age){
        cout << "Person() m_age:"<< age << endl;
    }
    ~Person(){
        cout << "~Person()" << endl;
    }
    void run(){
        cout << "run------" << m_age << endl;
    }
};
int main(){
    Person *p = new Person();
    {
        shared_ptr<Person> p1(p);
    }//析构~Person()
    {
        shared_ptr<Person> p2(p);
    }//析构~Person()
    getchar();
    return 0;
}
