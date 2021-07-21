//
//  main.cpp
//  019-类的声明和实现分离
//
//  Created by Cloud on 2021/7/20.
//

#include "main.hpp"
#include <iostream>
using namespace std;
#include "Person.hpp"
int main(){
    Person person;
    person.setAge(10);
    cout << "age is " << person.getAge() << endl;
    getchar();
    return 0;
}
