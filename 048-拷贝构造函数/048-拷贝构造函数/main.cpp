//
//  main.cpp
//  048-拷贝构造函数
//
//  Created by Cloud on 2021/9/27.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car {
    int m_price;
    int m_length;
public:
    Car(int price = 0,int length = 0):m_price(price),m_length(length){
        cout << "Car(int price = 0,int length = 0)" << endl;
    }
    //拷贝构造函数
    Car(const Car &car):m_price(car.m_price){
        cout << "Car(const Car &car)" << endl;
//        m_price = car.m_price;
//        m_length = car.m_length;
    }
    void display(){
        cout << "price=" << m_price << "length=" << m_length << endl;
    }
};
int main(){
    
    Car car1;
    Car car2(100);
    Car car3(100,5);
    
    //利用已经存在的car3对象，创建了一个car4新对象
    //car4对象初始化时会调用拷贝构造函数
    Car car4(car3);
    //若没有写拷贝构造函数，相当于如下
    /*
     car4.m_price = car3.m_price;
     car4.m_length = car3.m_length;
     */
    car4.display();
    
    getchar();
    return 0;
}
