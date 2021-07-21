//
//  main.cpp
//  013-封装
//
//  Created by Cloud on 2021/7/19.
//

#include "main.hpp"
#include <iostream>
using namespace std;

struct Person {
private:
    int m_age;
public:
    void setAge(int age){
        if (age < 0) {
            m_age = 1;
        }else{
            m_age = age;
        }
    }
    int getAge(){
        return m_age;
    }
};
int main(){
    Person person;
    person.setAge(10);
    cout << "age:" << person.getAge() << endl;
    return 0;
}
