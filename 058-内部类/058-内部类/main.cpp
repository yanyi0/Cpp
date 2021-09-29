//
//  main.cpp
//  058-内部类
//
//  Created by Cloud on 2021/9/29.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person{
private:
    int m_age;
    void test(){
    };
public:
    class Car{
    private:
        int m_price;
        void run(){
            
//            Person::m_age = 10;
//            Person::test();
//            Person person;
//            person.m_age = 10;
//            person.test();
//            m_age = 10;
//            test();
//            Person person;
//            person.m_age = 10;
        }
    };
};
//class Point {
//    class Math{
//        void test();
//    };
//};
//void Point::Math::test(){
//
//}
//class Point {
//    class Math;
//};
//class Point::Math{
//    void test(){
//
//    }
//};
class Point {
    class Math;
};
class Point::Math{
    void test();
};
void Point::Math::test(){
    
};
int main(){
    Person::Car car1;//内存布局仅仅只有4个字节m_age成员变量，不会有car对象
    Person::Car car2;
    getchar();
    return 0;
}
