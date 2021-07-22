//
//  main.cpp
//  029-纯虚函数
//
//  Created by Cloud on 2021/7/22.
//

#include "main.hpp"
#include <iostream>
using namespace std;

struct Animal{
    int m_age;
    virtual void speak() = 0;
    virtual void run() = 0;
    void eat(){
        
    }
};
struct Dog:Animal{
    void speak(){
        cout << "Dog::speak()" << endl;
    }
};
struct HaShiQi:Dog{
    void speak(){
        cout << "HaShiQi::speak()" << endl;
    }
    void run(){
        cout << "HaShiQi::run()" << endl;
    }
};
struct Cat:Animal{
    void speak(){
        Animal::speak();
        cout << "Cat::speak()" << endl;
    }
    void run(){
        cout << "Cat::run()" << endl;
    }
};
struct Pig:Animal{
    void speak(){
        cout << "Pig::speak()" << endl;
    }
    void run(){
        cout << "Pig::run()" << endl;
    }
};
int main(){
//    Dog *dog = new Dog();//只重写了一个虚函数，还是抽象类，不能创建对象
    HaShiQi *haShiQi = new HaShiQi();
//    Animal anim;//抽象类不能创建对象
//    Animal *ani = new Pig();
//    ani->speak();
//    ani->run();
    
    getchar();
    return 0;
}
