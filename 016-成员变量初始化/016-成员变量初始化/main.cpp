//
//  main.cpp
//  016-成员变量初始化
//
//  Created by Cloud on 2021/7/19.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Person {
    int m_age;
    Person(){
        memset(this, 0, sizeof(Person));
    };
};
//全局区:成员变量初始化为0
Person g_person;
int main(){
    
    Person *p = new Person[3]{};
    cout << p[0].m_age << endl;
    
    /*
    //栈空间:没有初始化成员变量，里面是cccccccc
    Person person;
    //堆空间:Windows没有初始化成员变量,Mac初始化了成员变量
    Person *p0 = new Person;
    //堆空间:成员变量初始化为0
    Person *p1 = new Person();
    
    cout << g_person.m_age << endl;
    cout << person.m_age << endl;//Windows报错
    cout << p0->m_age << endl;
    cout << p1->m_age << endl;
    */
    
    getchar();
    return 0;
}
