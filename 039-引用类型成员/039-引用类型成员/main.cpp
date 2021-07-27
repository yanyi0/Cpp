//
//  main.cpp
//  039-引用类型成员
//
//  Created by Cloud on 2021/7/27.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car{
    int age;
    int &m_price = age;
public:
    Car(int &price):m_price(price){}
};

int main(){
    
    return 0;
}
