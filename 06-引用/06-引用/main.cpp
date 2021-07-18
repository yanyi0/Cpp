//
//  main.m
//  06-引用
//
//  Created by Cloud on 2021/7/16.
//
#ifdef __cplusplus
#endif
#include <iostream>
using namespace std;
void test(){
    int age = 10;
//    int height = 20;
    //定义了一个age的引用，refAge相当于是age的别名
    int &ref = age;
    int &ref1 = ref;
    int &ref2 = ref1;
    
    ref += 10;
    ref1 += 10;
    ref2 += 10;
    
//    ref = height;
//    ref = 11;
    
    cout << age << endl;
}
void swag(int &v1,int &v2){
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
void test0(){
    int a = 10;
    int b = 20;
    swag(a,b);
    cout << "a = " << a << "b = " << b << endl;
    int c = 1;
    int d = 2;
    swag(c,d);
    cout << "c = " << c << "d = " << d << endl;
}
int main(int argc, const char * argv[]) {
    int age = 10;
    int *p = &age;
    *p = 20;
    cout << sizeof(p) << endl;
    int &ref = age;
    ref = 22;
    cout << sizeof(&age) << endl;
    cout << sizeof(&ref) << endl;
    return 0;
}
