//
//  main.m
//  010-对象
//
//  Created by Cloud on 2021/7/19.
//

#include <iostream>
using namespace std;
struct Car {
    //成员变量
    int m_price;
    //成员函数
    void run(){
        cout << "Car run():" << m_price << endl;
    }
};
struct Person {
    int age;
    void run(){
        cout << "Person run():" << age << endl;
    }
};
int main(int argc, const char * argv[]) {
    Car car;
    car.m_price = 10;
    car.run();
    Person person;
//    person.age = 10;
//    person.run();
    //通过指针间接访问person对象
    Person *p = &person;
    p->age = 30;
    p->run();
    return 0;
}
