//
//  add.hpp
//  066-模板分离
//
//  Created by Cloud on 2021/10/4.
//

#ifndef add_hpp
#define add_hpp

#include <stdio.h>
//int add(int a,int b);
//double add(double a,double b);
template<typename T> T add(T a,T b){
    return a+b;
}
#endif /* add_hpp */
