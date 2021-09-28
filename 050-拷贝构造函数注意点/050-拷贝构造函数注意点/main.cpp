//
//  main.cpp
//  050-拷贝构造函数注意点
//
//  Created by Cloud on 2021/9/28.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car {
    int m_price;
    int m_length;
public:
    Car(int price=0,int length=0):m_price(price),m_length(length){
        cout << "Car(int price=0,int length=0)" << endl;
    }
    Car(const Car &car):m_price(car.m_price),m_length(car.m_length){
        cout << "Car(const Car &car)" << endl;
    }
    void display(){
        cout << "price:" << m_price << " length:" << m_length << endl;
    }
};
int main(){
    Car car1(100,5);//Car(int price=0,int length=0)
    Car car2(car1);//Car(const Car &car)
    Car car3 = car2;//Car(const Car &car)
    Car car4;//Car(int price=0,int length=0)
    car4.display();//price:0 length:0
    car4 = car3;//不会调用拷贝构造函数，因为此时不是在初始化新对象，仅仅是赋值操作
    car4.display();//price:100 length:5
    getchar();
    return 0;
}
