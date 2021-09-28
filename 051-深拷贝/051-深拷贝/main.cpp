//
//  main.cpp
//  051-深拷贝
//
//  Created by Cloud on 2021/9/28.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car{
    int m_price;
    char *m_name;
public:
    Car(int price=0,const char *name = NULL):m_price(price){
        if(name == NULL) return;
        //申请新的堆空间
        m_name = new char[strlen(name)+1]{};
        //拷贝字符串数据到新的堆空间
        strcpy(m_name, name);
    }
    ~Car(){
        if (m_name == NULL) return;
        delete[] m_name;
        m_name = NULL;
    }
    void display(){
        cout << "price is " << m_price << ",name is " << m_name << endl;
    }
};
int main(){
//    const char *name = "bmw";
    char name2[] = {'b','m','w','\n'};
    Car *g_car = new Car(100,name2);//传入name2,是一个栈空间的地址，堆空间的对象的成员变量m_name指向栈空间的地址，一旦函数结束栈空间被回收，指向一块不安全区域
    g_car->display();
    getchar();
    return 0;
}
