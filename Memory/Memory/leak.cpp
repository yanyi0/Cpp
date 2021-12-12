//
//  leak.cpp
//  Memory
//
//  Created by Cloud on 2021/12/11.
//

#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <iostream>
class MyFancyObject{
private:
    size_t buffer_size_;
    char *buffer_;
public:
    MyFancyObject():buffer_size_(1024),buffer_((char*)malloc(buffer_size_)){};
    void say(){
        printf("buffer: %p,size:%ld\n",buffer_,(long)buffer_size_);
    }
    ~MyFancyObject(){
        free(buffer_);
    }
};
void TaskOne(){
    auto object = MyFancyObject();
    object.say();
}

int main(int argc,const char *argv[]){
    std::cout << "App Started\n";
    auto task1 = std::thread([]{
        for (;;) {
            TaskOne();
            usleep(100);
        }
    });
    task1.join();
    for (;;);
    return 0;
}
