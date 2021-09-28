//
//  main.cpp
//  044-智能指针auto_ptr缺陷
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
    //传入数组，创建10个person对象，但仅仅只会析构一次
//    {
//        SmartPointer<Person> p(new Person[10]);
//        p->run();
//    }
//    cout << 1 << endl;
//    {
//        shared_ptr<Person> p(new Person(20));
//        p->run();
//    }
//    cout << 2 << endl;
    //---------为嘛还会报错----------
    cout << 1 << endl;
    {
        shared_ptr<Person[]> p(new Person[5]);
    }
    cout << 2 << endl;
    //lamda表达式写法
//    cout << 1 << endl;
//    {
//        shared_ptr<Person> p(new Person[5],[](Person *p){
//            delete[] p;
//        });
//    }
//    cout << 2 << endl;
    
//    cout << 1 << endl;
//    {
//        shared_ptr<Person> p4;
//        {
//            shared_ptr<Person> p1(new Person(20));
//            shared_ptr<Person> p2 = p1;
//            shared_ptr<Person> p3 = p2;
//            p4 = p3;
//        }
//        cout << 2 << endl;
//    }
//    cout << 3 << endl;
    
//    {
//        shared_ptr<Person> p4;
//        {
//            shared_ptr<Person> p1(new Person(20));
//            cout << p1.use_count() << endl;
//            shared_ptr<Person> p2 = p1;
//            cout << p2.use_count() << endl;
//            shared_ptr<Person> p3 = p2;
//            cout << p3.use_count() << endl;
//            p4 = p3;
//            cout << p4.use_count() << endl;
//        }
//    }
    
//    {
//        shared_ptr<Person> p4;
//        {
//            shared_ptr<Person> p1(new Person(10));
//            cout << p1.use_count() << endl;//1
//            shared_ptr<Person> p3;
//            {
//                shared_ptr<Person> p2 = p1;
//                cout << p2.use_count() << endl;//2
//
//                p3 = p2;//3
//            }//2
//            cout << p3.use_count() << endl;
//            p4 = p3;//3
//            cout << p4.use_count() << endl;
//        }
//        cout << p4.use_count() << endl;//1
//    }
    getchar();
    return 0;
}
