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
//display_int
void display(int a){
    cout << "display(int a)" << endl;
}
//display_long
void display(long a){
    cout << "display(long a)" << endl;
}
//display_double
void display(double a){
    cout << "display(double a)" << endl;
}
int main(int argc, const char * argv[]) {
//    display(10);
//    funct();
//    func(10, 10.5);
//    func(10.5, 10);
//    cout << sum(10, 20) << endl;
//    cout << sum(10, 20, 30) << endl;
    return 0;
}
