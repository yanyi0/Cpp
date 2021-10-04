//
//  main.cpp
//  037-单例模式
//
//  Created by Cloud on 2021/7/25.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Rocket {
private:
    Rocket(){};
    //写成私有，防止外部调用delete rocket指针
    ~Rocket(){};
    //用指针更加灵活，放在堆区，不用随时delete掉，没有直接用static Rocket ms_rocket对象放在全局区，始终存在
    static Rocket *ms_rocket;
    void operator=(const Rocket &){};
    Rocket(const Rocket &){};
public:
    //这里要考虑多线程安全
    static Rocket *sharedRocket(){
        if (ms_rocket == NULL) {
            ms_rocket = new Rocket();
        }
        return ms_rocket;
    }
    //这里要考虑多线程安全
    static void deleteRocket(){
        if (ms_rocket != NULL) {
            delete ms_rocket;
            ms_rocket = NULL;
        }
    }
};
Rocket * Rocket::ms_rocket = NULL;
int main(){
    Rocket *rocket1 = Rocket::sharedRocket();
    Rocket *rocket2 = rocket1->sharedRocket();
//    *rocket1 = *rocket2;//同一个对象，赋值操作没有意义，要禁止掉，赋值运算符私有化
    Rocket *rocket3 = new Rocket(*rocket2);//可以调用拷贝构造函数，没有意义，禁止掉，拷贝构造函数私有化
    
//    int *p = new int;
//    *p = 10;
//    delete p;//回收内存空间，该块内存空间并不会被清零，可以重新被别人使用，内容被覆盖
//    Rocket *rocket1 = Rocket::sharedRocket();
//    Rocket *rocket2 = rocket1->sharedRocket();
//    delete rocket1;
//    Rocket *rocket2 = Rocket::sharedRocket();
//    Rocket *rocket3 = Rocket::sharedRocket();
//    Rocket *rocket4 = Rocket::sharedRocket();
    
//    cout << rocket1 << endl;
//    cout << rocket2 << endl;
//    cout << rocket3 << endl;
//    cout << rocket4 << endl;
    return 0;
}
