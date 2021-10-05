//
//  main.cpp
//  064-仿函数
//
//  Created by Cloud on 2021/10/4.
//

#include "main.hpp"
#include <iostream>
using namespace std;
int sum(int a,int b){
    return a+b;
}
class Sum {
    int m_age;
public:
    int operator()(int a,int b){
        cout << "operator()(int a,int b)" << endl;
        return a+b;
    }
    void func(){
        m_age = 10;
    }
};

int main(){
    Sum sum;
    sum.func();
    cout << sum(10,20) << endl;//相当于重载运算符()
    sum(20,30);
//    cout << sum.operator()(10,20) << endl;
    getchar();
    return 0;
}
