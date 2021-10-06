//
//  main.cpp
//  070-C++11新特性
//
//  Created by Cloud on 2021/10/6.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Person{
public:
    void run(){
        
    };
};
void func(int v){
    cout << "void func(int v) - " << v << endl;
}
void func(int *v){
    cout << "void func(int *v) - " << v << endl;
}
int main(){
    
    int array[] = {10,20,30,40,50};
    int array0[] {10,20,30,40,50};
    for(int item:array){
        cout << item << endl;
    }
    int m = NULL;
    int *n = nullptr;
    int *q = new int;
    delete q;
    q = nullptr;
    
//    func(NULL);
//    func(nullptr);
    
    int *p1 = NULL;
    int *p2 = nullptr;
    
    int b = 10;
    decltype(b) c = 20;//int
    
    auto a = 10;//int
    auto str = "c++";//const char *
    auto p = new Person();//Person *
    p->run();
    
    getchar();
    return 0;
}
