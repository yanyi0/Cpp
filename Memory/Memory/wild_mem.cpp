//
//  wild_mem.cpp
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
    ~MyFancyObject(){
        free(buffer_);
//        buffer_ = nullptr;
    }
    void say(){
        printf("buffer: %p,size: %ld\n",buffer_,(long)buffer_size_);
    }
    void write(char *data,size_t size){
        strncpy(buffer_, data, std::min(size,buffer_size_));
    }
    const char *getBuffer(){
        return buffer_;
    }
};
class Writer{
public:
    Writer(MyFancyObject &obj):obj_(obj){}
    void doWrite(char *data,size_t size){
            obj_.write(data, size);
    }
    void present(){
        printf("%s\n",obj_.getBuffer());
    }
private:
    MyFancyObject &obj_;
};
void TaskOne(){
    auto object = MyFancyObject();
    object.say();
}
void TaskTwo(){
    Writer *writer = nullptr;
    {
        MyFancyObject obj;
        writer = new Writer(obj);
    }
    if (writer) {
        //随机打印以下字符串
        std::string options[] = {
          "low",
          "medium",
          "high",
          "super",
        };
        std::string opt = options[arc4random()%4];
        writer->doWrite(const_cast<char *>(opt.c_str()), opt.length()+1);
        writer->present();
        delete writer;
    }
}
void TaskThree(){
    Writer *writer = nullptr;
    {
        auto obj = std::make_unique<MyFancyObject>();
        writer = new Writer(*obj);
    }
    if (writer) {
        writer->doWrite((char *)"XXXXXXXXXX", 10);
        delete writer;
    }
}
int main(int argc,const char *argv[]){
    std::cout << "App Started\n";
    auto task2 = std::thread([]{
        for (;;) {
            //Event Loop
            usleep(100);
            TaskTwo();
        }
    });
    auto task3 = std::thread([]{
        for (;;) {
            //Event Loop
            TaskThree();
        }
    });
    task2.join();
    task3.join();
    return 0;
}

