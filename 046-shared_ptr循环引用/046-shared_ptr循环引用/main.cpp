//
//  main.cpp
//  046-shared_ptr循环引用
//
//  Created by Cloud on 2021/9/7.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car;
class Person {
public:
    weak_ptr<Car> m_car;
    Person(){
        cout << "Person()" << endl;
    }
    ~Person(){
        cout << "~Person()" << endl;
    }
};
class Car{
public:
    shared_ptr<Person> m_person;
    Car(){
        cout << "Car()" << endl;
    }
    ~Car(){
        cout << "~Car()" << endl;
    }
};
int main(){
    
    {
        shared_ptr<Person> person(new Person());
        shared_ptr<Car> car(new Car());
        person->m_car = car;
        car->m_person = person;
    }
    getchar();
    return 0;
}
