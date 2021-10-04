//
//  main.cpp
//  061-运算符重载成员函数
//
//  Created by Cloud on 2021/9/30.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Point {
    friend istream &operator>>(istream &,Point &);
    friend ostream &operator<<(ostream &,const Point &);
    int m_x;
    int m_y;
public:
    int getX(){return m_x;};
    int getY(){return m_y;};
    Point(int x,int y):m_x(x),m_y(y){}
    void display() const{
        cout << "(" << m_x <<", " << m_y << ")" << endl;
    }
    const Point operator+(const Point &p) const{
        return Point(m_x+p.m_x, m_y+p.m_y);
    };
    const Point operator-(const Point &p) const{
        return Point(m_x-p.m_x, m_y-p.m_y);
    };
    Point &operator+=(const Point &p){
        m_x += p.m_x;
        m_y += p.m_y;
        return *this;
    };
    bool operator==(const Point &p) const{
//        if(m_x == p.m_x && m_y == p.m_y)
//            return 1;
//        else
//            return 0;
        return (m_x == p.m_x) && (m_y == p.m_y);
    };
    bool operator!=(const Point &p) const{
        return (m_x != p.m_x)|| (m_y != p.m_y);
    }
    const Point operator-() const{
        return Point(-m_x,-m_y);
    }
    //前置++
    Point &operator++(){
        m_x++;
        m_y++;
        return *this;
    }
    //后置++
    const Point operator++(int){
        //返回调用者之前的值
        Point old(m_x,m_y);
        m_x++;
        m_y++;
        return old;
    }
};
ostream &operator<<(ostream &cout,const Point &p){
    cout << "(" << p.m_x << "," << p.m_y << ")" ;
    return cout;
}
istream &operator>>(istream &cin,Point &p){
    cin >> p.m_x;
    cin >> p.m_y;
    return cin;
}
//系统自带打印字符串要求左边cout修饰为非const
void operator<<(ostream &cout,const char *string){
    
}

int main(){
    Point p1(10,20);
    Point p2 = p1++ + Point(30,40);
    cin >> p1 >> p2;
    cout << p1 << p2 << endl;
    
//    int a;
//    cin >> a;

//    cout << p1 << p2 << 1 << 2 << 3;
//    cout << p1;
//    cout << p2;
//    p1.display();
//    p2.display();
    
//    Point p2 = p1++ + Point(30, 40);
//    ++p1;
//    p1++;
    
//    Point p3 = -(-p1);
//    p1.display();
//    p3.display();
//    cout << (p1 != p2) << endl;
//    cout << (p1 == p2) << endl;
//    (p1 += p2) = Point(50,60);
//    p1.display();
//    Point p3(30,40);
//    Point p4 = p1+p2-p3;//相当于p1.operator+(p2).operator+(p3),但p1.operator+(p2)返回值是一个const修饰的对象，是无法直接调用非const修饰的成员函数的，此时需要将重载函数变为const修饰的重载函数
//    p1.operator+(p2).operator+(p3);
//    p4.display();
    //p1+p2 = Point(10,20);//此处赋值没有任何意义，运算符重载函数前加const修饰
    
//    Point p5 = p3 - p2;
//    p5.display();
    getchar();
    getchar();
    return 0;
}
