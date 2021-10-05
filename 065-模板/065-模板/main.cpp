//
//  main.cpp
//  065-模板
//
//  Created by Cloud on 2021/10/4.
//

#include "main.hpp"
#include <iostream>
using namespace std;
class Point{
    friend ostream &operator<<(ostream &cout,const Point &point);
    int m_x;
    int m_y;
public:
    Point(int x,int y):m_x(x),m_y(y){
        
    };
    //拷贝构造函数
    Point(const Point &point){
        cout << "Point(const Point &point)" << endl;
        m_x = point.m_x;
        m_y = point.m_y;
      }
    Point operator+(const Point &point){//返回值不能写成&，会报错Non-const lvalue reference to type 'Point' cannot bind to a temporary of type 'Point' 临时变量不能作为非const引用,临时变量的修改没有意义，属于const
        return Point(m_x+point.m_x,m_y+point.m_y);
    };
};
ostream &operator<<(ostream &cout,const Point &point){
    return  cout << "(" << point.m_x << ", " << point.m_y << ")" << endl;
}
//int add(int a,int b){
//    return a+b;
//}
//double add(double a,double b){
//    return a+b;
//}
//Point add(Point a,Point b){
//    return a+b;//a.operator+(b);
//}
template<typename T> T add(T a,T b){
    return a+b;
}
template<typename A,typename B,typename C> C add(A a,B b){
    return a+b;
}
int main(){
    
    cout << add<int>(10,20) << endl;
    cout << add<double>(2.5,2.6) << endl;
    cout << add<Point>(Point(10,20),Point(20,30)) << endl;
    
    cout << add(1,2) << endl;
    cout << add(2.5,2.6) << endl;
    cout << add(Point(10,20),Point(20,30)) << endl;
    getchar();
    return 0;
}
