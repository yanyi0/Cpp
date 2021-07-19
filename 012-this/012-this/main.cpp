//
//  main.cpp
//  012-this
//
//  Created by Cloud on 2021/7/19.
//

#include "main.hpp"
#include <iostream>
using namespace std;

//struct Person {
    //this指针存储着函数调用者的地址
    //this指向了函数调用者
//    int m_age;
//    void run(){
//        cout << "Person::run " << this->m_age << endl;
//        this->m_age = 3;
        //m_age = 3;this省略了,查看汇编和this->m_age是一样的
        //汇编
        /*
         //ecx中存放的是person1对象的地址
         //ebp-8是this指针的地址，存放person对象的地址
         //ebp-8存放的地址值赋值给eax寄存器
         //将3放入eax寄存器中存放的地址值的内存空间
         mov dword ptr [ebp-8],ecx
         mov eax,dword ptr [ebp-8]
         mov dword ptr [eax],3
         */
//    }
//};
struct Person {
    int m_id;
    int m_age;
    int m_height;
    void display(){
        //eax == &person.m_age == &person+4
        //mov eax,dword ptr [this]
        //[eax]、[eax+4]、[eax+8]
        //[&person+4]、[&person+4+4]、[&person+4+8]
        //40           50            0xcccccccc
        cout << "id = " << m_id << ", age = " << m_age << ", height = " << m_height << endl;
    }
};
int main(){
    /*
    Person person1;
    person1.m_age = 1;
    person1.run();
    
    Person person2;
    person2.m_age = 2;
    person2.run();
     */
    
    Person person;
    person.m_id = 10;
    person.m_age = 20;
    person.m_height = 30;
    person.display();
    
    Person *p = (Person *)&person.m_age;
    //eax == &person.m_age == &person + 4
    //mov eax,dword ptr [p]
    //mov dword ptr [eax+0],40
    //mov dword ptr [&person+4+0],40
    p->m_id = 40;
    //mov dword ptr [eax + 4],50
    //mov dword ptr [&person + 4 + 4],50
    p->m_age = 50;
    //将person对象的地址值传给display()函数的this
//    person.display();
    //会将指针p里面存储的地址传递给display()函数的this
    //将&person.m_age传递给display()函数的this
    p->display();
    /*
    dword ptr [ebp-14h],0Ah
    dword ptr [ebp-10h],14h
    dword ptr [ebp-0Ch],1Eh
     */
//    Person *p = &person;
//    p->m_id = 10;
//    p->m_age = 10;
//    p->m_height = 10;
//    p->display();
    /*
     //Person *p = &person
     //ebp-14h是person对象的地址
     lea eax,[ebp-14h]
     //ebp-20h是指针变量p的地址，存放对象person的地址
     mov dword ptr [ebp-20h],eax
     //eax存储的是person对象的地址，也就是person.m_id的地址
     //p->m_id = 10;
     mov eax,dword ptr [ebp-20h]
     mov dword ptr [eax],0Ah
     
     //p->m_age = 10;
     mov eax,dword ptr [ebp-20h]
     mov dword ptr [eax+4],0Ah
     
     //p->m_height = 10
     mov eax,dword ptr [ebp-20h]
     mov dword ptr [eax+8],0Ah
     
     mov eax,dword ptr [ebp-20h]
     call 003B141F
     */
    return 0;
}
