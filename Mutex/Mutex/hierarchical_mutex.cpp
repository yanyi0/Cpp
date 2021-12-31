//
//  hierarchical_mutex.cpp
//  Mutex
//
//  Created by Cloud on 2021/12/25.
//

#include "hierarchical_mutex.hpp"
#include <iostream>
 
thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value = ULONG_MAX;
 
void hierarchical_mutex::lock()
{
    check_hierarchy();
    _internal_lock.lock();
    update_hierarchy();
}
 
void hierarchical_mutex::unlock()
{
    this_thread_hierarchy_value = _previous_hierarchy_value;
    _internal_lock.unlock();
}
 
bool hierarchical_mutex::try_lock()
{
    check_hierarchy();
    if (_internal_lock.try_lock()) {
        update_hierarchy();
        return true;
    }
    return false;
}
 
void hierarchical_mutex::check_hierarchy()
{
    if (_hierarchy_value >= this_thread_hierarchy_value) {
        //throw std::logic_error("错误！！ 层次锁套用顺序不对。");
        std::cout << "error !!! 层次锁套用顺序不对。" << std::endl;
    }
}
 
void hierarchical_mutex::update_hierarchy()
{
    _previous_hierarchy_value = this_thread_hierarchy_value;
    this_thread_hierarchy_value = _hierarchy_value;
}
