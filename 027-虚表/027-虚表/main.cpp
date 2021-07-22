//
//  main.cpp
//  027-虚表
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
};
struct Dog:Animal{
    void speak(){
        cout << "Dog::speak()" << endl;
    }
    void run(){
        cout << "Dog::run()" << endl;
    }
};
struct Cat:Animal{
    int m_life;
    void speak(){
        Animal::speak();
        cout << "Cat::speak()" << endl;
    }
    void run(){
        cout << "Cat::run()" << endl;
    }
};
struct WhiteCat:Cat{
    void speak(){
        cout << "WhiteCat::speak()" << endl;
    }
    void run(){
        cout << "WhiteCat::run()" << endl;
    }
};
struct Pig:Animal{
//    void speak(){
//        cout << "Pig::speak()" << endl;
//    }
//    void run(){
//        cout << "Pig::run()" << endl;
//    }
};
void liu(Animal *p){
    p->speak();
    p->run();
}
int main(){
    
    Animal *ani = new Cat();
    ani->speak();
    ani->run();
    
//    Animal *ani = new WhiteCat();
//    ani->speak();
//    ani->run();
//
//    Cat *cat = new WhiteCat();
//    cat->speak();
//    cat->run();
    
//    Animal *ani = new Animal();
//    ani->m_age = 20;
//    ani->speak();
//    ani->run();
    
//    Animal *cat = new Cat();
//    cat->m_age = 20;
//    cat->speak();
//    cat->run();
//
//    cat = new Pig();
//    cat->speak();
//    cat->run();
    /*
    liu(new Dog());
    liu(new Cat());
    liu(new Pig());
     */
    return 0;
}
