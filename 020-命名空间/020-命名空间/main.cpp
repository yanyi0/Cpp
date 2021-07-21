//
//  main.cpp
//  020-命名空间
//
//  Created by Cloud on 2021/7/20.
//

#include "main.hpp"
#include <iostream>
using namespace std;

//class Person{
//    int m_age;
//};

namespace Cloud {
     int m_age;
     void func(){
         cout << "Cloud::func" << endl;
     };
     class Person{
         int m_age;
         int m_name;
     };
}

void func(){
    cout << "func()" << endl;
}

namespace Fish {
     int m_age;
     void func(){
         cout << "Fish::func()" << endl;
     };
}
namespace ManKind {
   int m_name;
}
namespace ManKind {
   int m_sex;
}
int main(){
    using namespace Cloud;
    using namespace Fish;
//    m_age = 1;//二义性，Cloud和Fish里面均有m_age
    Fish::func();
    ::func();
    ::Cloud::func();
    
//    Cloud::m_age = 10;
//    Cloud::func();
    
//    Cloud::Person person;
//    cout << sizeof(person) << endl;
    return 0;
}
