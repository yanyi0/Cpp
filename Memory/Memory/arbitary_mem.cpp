//
//  arbitary_mem.cpp
//  Memory
//
//  Created by Cloud on 2021/12/11.
//

#include <stdio.h>
#include <iostream>

class Cat{
public:
    char name[4];
    int age;
    void show(){
        std::cout << "cat name:" << name << ", age:" << age << std::endl;
    }
};

class Dog{
public:
    char tag[4];
    char name[8];
    int year;
    void show(){
        std::cout << "dog name:" << name << ",age:" << year << std::endl;
    }
    void setName(char *name_){
        strcpy(name, name_);
    }
};

int main(){
    Cat cat = {
        .name = "Tom",
        .age = 6,
    };
    Dog *dog = (Dog *)&cat;
    dog->setName((char *)"d");
    cat.show();
    return 0;
}
