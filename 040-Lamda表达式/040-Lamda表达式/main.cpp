//
//  main.cpp
//  040-Lamda表达式
//
//  Created by Cloud on 2021/9/6.
//

#include "main.hpp"
#include <iostream>
using namespace std;

int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int multip(int a,int b){
    return a*b;
}
int divide(int a,int b){
    return a/b;
}
int calculate(int v1,int v2,int (*func)(int,int)){
    return func(v1,v2);
}
int main(){
//    cout << calculate(20, 10, add) << endl;
//    cout << calculate(20, 10, sub) << endl;
//    cout << calculate(20, 10, multip) << endl;
//    cout << calculate(20, 10, divide) << endl;
    
    cout << calculate(20, 10, [](int v1,int v2){return  v1+v2;}) << endl;
    cout << calculate(20, 10, [](int v1,int v2){return  v1-v2;}) << endl;
    cout << calculate(20, 10, [](int v1,int v2){return  v1*v2;}) << endl;
    cout << calculate(20, 10, [](int v1,int v2){return  v1/v2;}) << endl;
    getchar();
    return 0;
}
void testFunc(){
    ([]{
        cout << "func()" << endl;
    })();
    void (*p)() = []{
        cout << "func()" << endl;
    };
    p();
    
    auto p0 = []{
        cout << "func()-----" << endl;
    };
    p0();
    p0();
    
    auto p1 = [](int a,int b)->int{
        return a+b;
    };
    cout << p1(10,20) << endl;
}
