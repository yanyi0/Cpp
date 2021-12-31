//
//  hierarchical_mutex.hpp
//  Mutex
//
//  Created by Cloud on 2021/12/25.
//

//hierarchical_mutex.h文件
 
#pragma once
#include <mutex>
class hierarchical_mutex {
public:
    static thread_local unsigned long this_thread_hierarchy_value;
 
    explicit hierarchical_mutex(unsigned long value) :_hierarchy_value(value), _previous_hierarchy_value(0){};
    void lock();
    void unlock();
    bool try_lock();
 
private:
    unsigned long const _hierarchy_value;
    unsigned long _previous_hierarchy_value;
    void check_hierarchy();
    void update_hierarchy();
    std::mutex _internal_lock;
};
