//
//  parent.cpp
//  虚函数多态
//
//  Created by Cloud on 2021/12/12.
//

#include <stdio.h>

#include <iostream>
using namespace std; 
class Parent
{
public:
    Parent()
    {
        // 父类的构造方法中执行虚函数，会发生多态吗？
        fun();
    }
    virtual void fun()
    {
        cout << "父类" << endl;
    }
};
class Child : public Parent
{
public:
    Child()
    {
        fun();
    }
    void fun()
    {
        cout << "子类" << endl;
    }
};
 
int main()
{
    Child c;
    return 0;
}
