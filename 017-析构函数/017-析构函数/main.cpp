//
//  main.cpp
//  017-析构函数
//
//  Created by Cloud on 2021/7/20.
//

#include "main.hpp"
#include <iostream>
using namespace std;
struct Person {
    int m_age;
    Person(){
        memset(this, 0, sizeof(Person));
        cout << "Person Person()" << endl;
    };
    ~Person(){
        cout << "Person ~Person()" << endl;
    }
};
int main(){
    Person *p = new Person;
    //堆空间的地址值
    cout << p << endl;
    //栈空间的地址值
    cout << &p << endl;
    delete p;
    /*
    Person * p = (Person *)malloc(sizeof(Person));
    free(p);
     */
    
    /*
    cout << 1 << endl;
    {
        Person person;
    }
    cout << 2 << endl;
     */
    getchar();
    return 0;
}
