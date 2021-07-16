//
//  main.m
//  03-Extern_C
//
//  Created by Cloud on 2021/7/14.
//

#include <iostream>
using namespace std;
#include "math.h"
//extern "C" void func(){
//
//}
//extern "C" void func(int v1){
//
//}
//extern "C" {
//    void func(){
//
//    }
//    void func(int v1){
//
//    }
//}
//extern "C" void func();
//extern "C" void func0(int v1);
//extern "C" {
//    void func();
//    void func0(int v1);
//}
//extern "C" {
//int sum(int v1,int v2);
//int sub(int v1,int v2);
//}
//extern "C" {
//     #include "main.h"
//}
#include "main.h"
extern "C" {
#include "other.h"
}
int main(void) {
    
    other();
    
    cout << sum(10, 20) << endl;
    cout << sub(30, 20) << endl;
    cout << divide(30, 2) << endl;
    
    getchar();
    return 0;
}
//extern "C" void func(){
//
//}
//extern "C" void func0(int v1){
//
//}
