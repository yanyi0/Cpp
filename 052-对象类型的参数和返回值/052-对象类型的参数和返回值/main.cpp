//
//  main.cpp
//  052-对象类型的参数和返回值
//
//  Created by Cloud on 2021/9/28.
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
    Car(const Car &car){
        cout << "Car(const Car &) - " << this << endl;
    }
    void run(){
        cout << "run()" << endl;
    }
};
void test1(Car &car){
    
}
Car test2(){
    Car car;
    return car;
}
int main(){
    
      Car car3 = test2();
    
//    Car car2;
//    car2 = test2();
    
//    Car car1;
//    test1(car1);
    
//    getchar();
    return 0;
}
