//
//  main.cpp
//  069-类型转换
//
//  Created by Cloud on 2021/10/6.
//

#include "main.hpp"
#include <iostream>
using namespace std;

class Person{
    int m_age;
    virtual void run(){};
};
class Student:public Person{
    
};
class Car{
    int m_age;
    int m_price;
    int m_height;
};

int main(){
    int *p = reinterpret_cast<int *>(0x100);
    int b = reinterpret_cast<int>(p);
    //小端模式0A 00 00 00/0000 1010 0000 0000 0000 0000 0000 0000
    int a = 10;
    double d = reinterpret_cast<double&>(a);
    //汇编代码如下
    /**
     movsd xmm0,mmword ptr [a]
     movsd mmword ptr [d],xmm0
     二进制拷贝完成后d中内存空间为
     0A 00 00 00 cc cc cc cc
     */
    
    //0A 00 00 00 00 00 00 00理想情况
    //00 00 00 00 00 00 24 40实际情况,浮点数据的存储和整形数据的存储是不一样的，寄存器的使用不同
//    double d = a;
    //理想情况下汇编代码
    //mov eax,dword ptr [a]
    //mov dword ptr [d], eax
    /**实际情况
     汇编代码如下，并不是简简单单的二进制拷贝
     xmm0,mmword ptr [__real@4024000000000000 (0979CA0h)]
     mmword ptr [d],xmm0
     */
    cout << "a = " << a << endl;
    cout << "d = " << d << endl;
    
//    int a = 10;
//    double b = static_cast<int>(a);
    
//    Person *p1 = new Person();
//    const Person *p2 = static_cast<const Person *>(p1);//相当于const Person *p2 = p1;不写转换也会自动转
//    Car *c1 = dynamic_cast<Car *>(p1);
//    Car *c2 = static_cast<Car *>(p1);

    //原始做法
//    Student *stu1 = (Student *)p1;
//    Student *stu2 = (Student *)p2;
//    Student *stu1 = dynamic_cast<Student *>(p1);//不安全，子类指针指向父类对象
//    Student *stu2 = dynamic_cast<Student *>(p2);//安全
//    cout << "stu1=" << stu1 << endl;
//    cout << "stu1=" << stu2 << endl;
    
//    const Person *p1 = new Person();
//    Person *p2 = const_cast<Person *>(p1);
//    Person *p3 = (Person *)p1;
    
//    int a = 10;
//    double d = static_cast<double>(a);
    //隐式转换
//    double d = a;
    //显式转换
//    double d = (double) a;
//    double e = double(a);
    
    getchar();
    return 0;
}
void test_dynamic(){
    Person *p1 = new Person();
    Person *p2 = new Student();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    Car *c1 = (Car *)p1;
    Car *c2 = dynamic_cast<Car *>(p2);
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
}
