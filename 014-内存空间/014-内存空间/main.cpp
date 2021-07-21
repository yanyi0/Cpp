//
//  main.cpp
//  014-内存空间
//
//  Created by Cloud on 2021/7/19.
//

#include "main.hpp"
#include <iostream>
using namespace std;
void test2(){
    int *p = new int;
    *p = 10;
    delete p;
    
    char *q = new char;
    *q = 10;
    delete q;
    
    char *s = new char[4];
    delete[] s;
}
void test3(){
    int *p = (int *)malloc(4);
    *p = 0;
    
    //将4个字节中的每一个字节都设置为1，并不是将4个字节设置为1
    int size = sizeof(int) * 10;
    int *q = (int *)malloc(size);
    //momery set
    memset(q, 0, size);
    //从p地址开始的连续4个字节中的每一个字节都设置为1
    //memset(q,1,4);
    //将4个字节设置为1
    //00000000 00000000 00000000 00000001
    //将4个字节中的每一个字节都设置为1
    //00000001 00000001 00000001 00000001
}
void test4(){
    int *p0 = new int;//Mac平台会初始化为0，Windows平台未初始化
    int *p1 = new int();
    int *p2 = new int(5);
    cout << *p0 << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;
}
struct Person {
    int m_age;
};
//全局区
Person g_person;
int main(){
    //栈空间
    Person person;
    //堆空间
    Person *per = new Person;
    test4();
//    test2();
    
    int *p = (int *)malloc(4);
    *p = 10;
    free(p);
    
    char *q = (char *)malloc(4);
    q[0] = 10;
    q[1] = 11;
    q[2] = 12;
    q[3] = 13;
    free(q);
    /*
    *q = 10;
    *(q+1) = 11;
    *(q+2) = 12;
    *(q+3) = 13;
    */
    return 0;
}
