//
//  main.m
//  09-引用数组
//
//  Created by Cloud on 2021/7/19.
//
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    //数组名arr其实是数组的地址，也是数组首元素的地址
    //数组名arr可以看做是指向数组首元素的指针(int *)
    int arr[] = {1,2,3};
    int (&ref)[3] = arr;
    ref[1] = 0;
    int * const &ref0 = arr;
    ref0[1] = 0;
    return 0;
}
