//
//  main.cpp
//  011-对象内存
//
//  Created by Cloud on 2021/7/19.
//

#include "main.hpp"
#include <iostream>
using namespace std;

struct Person{
    int m_id;
    int m_age;
    int m_height;
};
int main(){
    Person person;
    person.m_id = 1;
    person.m_age = 2;
    person.m_height = 3;
    cout << "person = " << &person << endl;
    cout << "m_id = " << &person.m_id << endl;
    cout << "m_age = " << &person.m_age << endl;
    cout << "m_height = " << &person.m_height << endl;
    getchar();
    return 0;
}

