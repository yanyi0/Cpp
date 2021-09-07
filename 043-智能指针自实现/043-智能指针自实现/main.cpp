//
//  main.cpp
//  043-智能指针自实现
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
template <typename T>
class SmartPointer{
private:
    T *m_obj;
public:
    SmartPointer(T *obj):m_obj(obj){
    }
    ~SmartPointer(){
        if (m_obj == nullptr) return;
        delete m_obj;
    }
    T *operator->(){
        return m_obj;
    }
};
int main(){
    cout << 1 << endl;
    {
        SmartPointer<Person> p(new Person(20));
        p->run();
    }
    cout << 2 << endl;
    getchar();
    return 0;
}
