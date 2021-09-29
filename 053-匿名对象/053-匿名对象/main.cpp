//
//  main.cpp
//  053-匿名对象
//
//  Created by Cloud on 2021/9/29.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Car{
public:
    int m_price;
    Car(){
        cout << "Car() - " << this << endl;
    }
    ~Car(){
        cout << "~Car() - " << this << endl;
    }
    Car(const Car &car){
        cout << "Car(const Car &) - " << this << endl;
    }
    void run(){
        cout << "run()" << this << endl;
    }
};
void test(Car car){
    
}
Car test2(){
    return Car();
}
int main(){
    Car car;
    car = test2();
    car.run();
//      test(Car());
//    cout << 1 << endl;
//    Car().run();
//    cout << 2 << endl;
    
    getchar();
    return 0;
}
