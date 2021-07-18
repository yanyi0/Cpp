//
//  main.m
//  08-引用补充
//
//  Created by Cloud on 2021/7/18.
//

#include <iostream>
using namespace std;

int main() {
    /*
    int age = 10;
    const int &ref = age;
    age = 30;
    cout << "age is " << age << endl;
    cout << "reg is " << ref << endl;
     */
    int age = 10;
    const long &ref = age;
    age = 30;
    cout << "age is " << age << endl;
    cout << "reg is " << ref << endl;
    getchar();
    return 0;
}
