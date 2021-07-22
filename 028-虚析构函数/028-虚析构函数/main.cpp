//
//  main.cpp
//  028-虚析构函数
//
//  Created by Cloud on 2021/7/22.
//

#include "main.hpp"
#include <iostream>
using namespace std;

struct Animal{
    int m_age;
    virtual void speak(){
        cout << "Animal::speak()" << endl;
    }
    virtual void run(){
        cout << "Animal::run()" << endl;
    }
    Animal(){
        cout << "Animal::Animal()" << endl;
    }
    virtual ~Animal(){
        cout << "Animal::~Animal()" << endl;
    }
};

struct Cat:Animal{
    int m_life;
    void speak(){
        cout << "Cat::speak()" << endl;
    }
    void run(){
        cout << "Cat::run()" << endl;
    }
    Cat(){
        cout << "Cat::Cat()" << endl;
    }
    ~Cat(){
        cout << "Cat::~Cat()" << endl;
    }
};
int main(){
    Animal *ani = new Cat();
    delete ani;
    return 0;
}
