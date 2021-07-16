//
//  main.m
//  02-函数重载
//
//  Created by Cloud on 2021/7/13.
//

#include <iostream>
using namespace std;

int sum(int v1,int v2){
    return v1+v2;
}
int sum(int v1,int v2,int v3){
    return v1 + v2 + v3;
}
void func(){
    cout << "func()" << endl;
}
void func(int v1,double v2){
    cout << "func(int v1,double v2)" << endl;
}
void func(double v1,int v2){
    cout << "func(double v1,int v2)" << endl;
}
//int funct(){
//    return 0;
//}
//double funct(){
//    return 0;
//}
//void display(){
//    cout << "display()" << endl;
//}
//display_int
//void display(int a){
//    cout << "display(int a)" << endl;
//}
//display_long
//void display(long a){
//    cout << "display(long a)" << endl;
//}
//display_double
//void display(double a){
//    cout << "display(double a)" << endl;
//}
int age = 33;
void test(){
    cout << "test()" << endl;
}
//void display(int a=11,int b = 22,int c = age,void(*func)() = test){
//    cout << "a is" << a << endl;
//    cout << "b is" << b << endl;
//    cout << "c is" << c << endl;
//    func();
//}
//void display(int a){
//    cout << "a is " << a << endl;
//}
void display(int a = 10, int b=20){
    cout << "a is " << a << endl;
}
int main(int argc, const char * argv[]) {
    display(30,40);
//      display(10);
//    display(10);
//    funct();
//    func(10, 10.5);
//    func(10.5, 10);
//    cout << sum(10, 20) << endl;
//    cout << sum(10, 20, 30) << endl;
    return 0;
}
