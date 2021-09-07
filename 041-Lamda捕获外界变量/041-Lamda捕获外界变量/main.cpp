//
//  main.cpp
//  041-Lamda捕获外界变量
//
//  Created by Cloud on 2021/9/6.
//

#include "main.hpp"
#include <iostream>
using namespace std;
int main(){
    int a=10;
    //值捕获
//    auto func = [a]{
//        cout << a << endl;
//    };
//    a=20;
//    func();
//    auto func = [&a]{
//        cout << a << endl;
//    };
//    a=20;
//    auto func = [&a]{
//        a++;
//    };
//    func();
//    cout << a << endl;
    
//    auto func = [a]()mutable{
//        a++;
//        cout << "lamda =" << a << endl;
//    };
//    func();
//    cout << a << endl;
    
//    auto func1 = [](auto v1,auto v2){return v1+v2;};
//    cout << func1(10, 12.5) << endl;
    
    int b;
    auto func0 = [b=10](){
        cout << b << endl;
    };
    func0();
    //这里仍然未初始化
    cout << b << endl;
    getchar();
    return 0;
}
