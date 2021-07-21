//
//  Person.cpp
//  019-类的声明和实现分离
//
//  Created by Cloud on 2021/7/20.
//

#include "Person.hpp"
void Person::setAge(int age){
    m_age = age;
}
int Person::getAge(){
    return m_age;
}
Person::Person(){
    m_age = 0;
}
Person::~Person(){
    
};
