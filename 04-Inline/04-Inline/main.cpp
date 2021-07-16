//
//  main.m
//  04-Inline
//
//  Created by Cloud on 2021/7/15.
//

#include <iostream>
using namespace std;
//开辟栈空间
void func(){
    cout << "void func1()" << endl;
    cout << "void func2()" << endl;
    cout << "void func3()" << endl;
}//回收栈空间
int sum(int v1,int v2){
    return v1+v2;
}
inline void func0(){
    cout << "void func1()" << endl;
    cout << "void func2()" << endl;
    cout << "void func3()" << endl;
}
int sum0(int v1,int v2){
    return v1+v2;
}
#define add(v) v+v

int main(int argc, const char * argv[]) {
    int a = 10;
    int c = add(++a);
    cout << c << endl;
    func0();
    cout << sum0(10, 20) << endl;
    func();
    cout << sum(10, 20) << endl;
    return 0;
}
