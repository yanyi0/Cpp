//
//  main.cpp
//  047-unique_ptr
//
//  Created by Cloud on 2021/9/7.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person {
public:
    int m_age;
    Person(){
        cout << "Person()" << endl;
    }
    Person(int age):m_age(age){
        cout << "Person(int age )"<< m_age << endl;
    }
    ~Person(){
        cout << "~Person()" << endl;
    }
};
int main(){
//    {
//        unique_ptr<Person> person(new Person(20));
//        //unique_ptr<Person> p1(person);//多个智能指针指向同一个对象，编译报错
//    }
    
    unique_ptr<Person> p0;
    {
        //p1强引用着person对象
        unique_ptr<Person> p1(new Person(20));
        //转移之后，p0强引用着person对象
        p0 = std::move(p1);
    }
    getchar();
    return 0;
}
