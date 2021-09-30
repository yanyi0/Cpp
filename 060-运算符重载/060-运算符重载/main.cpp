//
//  main.cpp
//  060-运算符重载
//
//  Created by Cloud on 2021/9/29.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Point {
    friend Point operator+(const Point &,const Point &);
private:
    int m_x;
    int m_y;
public:
    int getX(){return m_x;};
    int getY(){return m_y;};
    Point(int x,int y):m_x(x),m_y(y){}
    void display(){
        cout << "(" << m_x <<", " << m_y << ")" << endl;
    }
};
Point operator+(const Point &p1,const Point &p2){
    cout << "Point operator+(Point p1,Point p2)" << endl;
    return Point(p1.m_x+p2.m_x, p1.m_y+p2.m_y);
};
int main(){
    Point p1(10,20);
    Point p2(20,30);
    Point p3(30,40);
    Point p4 = p1+p2+p3;
    //Point p5 = operator+(operator+(p1,p2),p3);
    p4.display();
    getchar();
    return 0;
}
