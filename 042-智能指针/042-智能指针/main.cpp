//
//  main.cpp
//  042-智能指针
//
//  Created by Cloud on 2021/9/6.
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
void test(){
//    Person *p = new Person();
    //可以理解为:只能指针p指向了堆空间的person对象
//    auto_ptr<Person> p(new Person(20));
//    p->run();
//    cout << 1 << endl;
//    {
//        auto_ptr<Person> p(new Person(20));
//        p->run();
//    }
//    cout << 2 << endl;
    
    cout << 1 << endl;
    {
        Person person(10);
        auto_ptr<Person> p(&person);
        p->run();
    }
    cout << 2 << endl;
}
int main(){
    test();
    
    getchar();
    return 0;
}
