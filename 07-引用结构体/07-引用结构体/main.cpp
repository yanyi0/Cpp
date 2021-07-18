//
//  main.m
//  07-引用结构体
//
//  Created by Cloud on 2021/7/17.
//

#include <iostream>
using namespace std;
struct Date {
    int year;
    int month;
    int day;
};
void test(){
    //    Date d = {2011,1,5};
    //    Date &ref = d;
    //    ref.year = 2014;
        
    //    int age = 10;
    //    int *p = &age;
    //    int *&ref = p;
    //    *ref = 30;
    //    int height = 30;
    //    ref = &height;
        
    //    int array[] = {1,2,3};
    //    int (&arr)[3] = array;
    //
    //    int *p;
    //    //指针数组
    //    int *a[3] = {p,p,p};
    //    //数组指针:指向数组的指针
    //    int (*ar)[3] = &array;
}
void test0(){
    int age = 10;
    const int &ref = age;
    const int *p = &age;
    
//    ref = 30;
//    *p = 30;
    
    cout << ref << endl;
    cout << *p << endl;
}
void test1(){
    int height = 20;
    int age = 10;
    
    //ref1不能修改指向，但是可以通过ref1间接修改指向的变量的值
//    int& const ref1 = age;const可以直接去掉，引用本来就不能修改指向
//    ref1 = 30;不报错
    //ref2不能修改指向，不可以通过ref2间接修改指向的变量的值
    int const &ref2 = age;
//    ref2 = 30;报错
    
    //p1不能修改指向，可以利用p1间接修改指向的变量
    int * const p1 = &age;
    *p1 = 40;
    
    //p2可以修改指向，不可以利用p2间接修改指向的变量
    int const *p2 = &age;
//    *p2 = 50;报错
    p2 = &height;
}
int func(){
    return 8;
}
int sum(int &v1,int &v2){
    cout << "sum(int &v1,int &v2)" << endl;
    return v1 + v2;
}
int sum(const int &v1,const int &v2){
    cout << "sum(const int &v1,const int &v2)" << endl;
    return v1 + v2;
}

int main(int argc, const char * argv[]) {
    //非const实参
    int c = 10;
    int d = 20;
    sum(c, d);
    
    //const实参
    const int e = 10;
    const int f = 20;
    sum(e, f);
    
    sum(10, 20);
    
    int a = 1;
    int b = 2;
    const int &ref = 30;
    const int &ref0 = a + b;
    const int &ref1 = func();
    
    int age = 10;
    const double &ref3 = age;
    
    getchar();
    return 0;
}
