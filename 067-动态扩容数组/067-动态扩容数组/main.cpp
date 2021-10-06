//
//  main.cpp
//  068-动态扩容数组模板
//
//  Created by Cloud on 2021/10/5.
//

#include "main.hpp"
#include <iostream>
#include "Array.hpp"
using namespace std;

class Point {
    friend ostream &operator<<(ostream &,const Point &);
    int m_x;
    int m_y;
public:
    Point(int x=0,int y=0):m_x(x),m_y(y){
        
    }
};
ostream &operator<<(ostream &cout,const Point &point){
    return cout << "(" << point.m_x << ", " << point.m_y << ")";
}

int main(){
    Array<Point> array;
    array.add(Point(1,2));
    array.add(Point(3,4));
    array.add(Point(5,6));
    cout << array << endl;
    
//    Array<int> array;//类型必须写，否则构造函数不知道类型
//    array.add(10);
//    array.add(20);
//    array.add(30);
//    array.add(40);
//    array.add(50);
//    cout << array << endl;
    
//    cout << array.get(0) << endl;
//    cout << array[1] << endl;
//    cout << array.size() << endl;
//    Array<void *> array;
//    array.add(&Point(1, 2));//数据不安全，临时对象放入数组中，临时对象会马上销毁，马上销毁还存入地址值
//    array.add(new Point(3,4));//数据不安全，堆空间的对象，没有看到delete对象被销毁
//    array.add(new Car());
    
    getchar();
    return 0;
}
