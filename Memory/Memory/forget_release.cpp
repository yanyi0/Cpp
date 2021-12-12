//
//  forget_release.cpp
//  Memory
//
//  Created by Cloud on 2021/12/11.
//

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <unistd.h>

class GuessGame{
public:
    void Start(){
        //欢迎
        welcome();
        //生成随机数
        generate();
        //猜五次
        for(int i = 0;i<5;++i){
            int guess = getUserInput();
            int result = compare(guess);
            showTips(result);
            if (result == 0) {
                win = true;
                break;
            }
        }
    }
    void stop(){};
private:
    void welcome(){
        std::cout << "\n Welcome to Guess Game,guess a number between 0-100\n";
    }
    void generate(){
        number = arc4random() % 100;
    }
    int getUserInput(){
        std::cout << "Guess the number: ";
        int x;
        std::cin >> x;
        return x;
    }
    int compare(int x){
        return x < number ? -1 :x > number ? 1:0;
    }
    void showTips(int compareResult){
        if (compareResult < 0) {
            std::cout << "Too small!";
        }else if(compareResult > 0){
            std::cout << "Too big!";
        }else{
            std::cout << "Correct!";
        }
        std::cout << std::endl;
    }
public:
    //保存游戏结果
    int win = false;
private:
    //要猜的随机数
    int number;
    //方便展示
    char padding[102400];
};
class ScoreUploader{
public:
    ScoreUploader(){
        //上报线程,轮询上报队列上报
        _thread = std::thread([this]{
            for (;;) {
                {
                    std::lock_guard<std::mutex> l(mu);
                    if (!games.empty()) {
                        //Upload last game result
                        //do_report(games.front())
                        games.pop_back();
                        sleep(2);
                    }
                }
                sleep(1);
            }
        });
    }
    ~ScoreUploader(){
        _thread.join();
    }
    void Upload(std::unique_ptr<GuessGame> game){
        //将完成的游戏加入上报队列
        std::lock_guard<std::mutex> l(mu);
        games.push_back(std::move(game));
    }
private:
    std::thread _thread;
    std::mutex mu;
    std::vector<std::unique_ptr<GuessGame>> games;
};

//-------------------------------------------------

int main(int argc,const char *argv[]){
    ScoreUploader uploader;
    for (;;) {
        auto game = std::make_unique<GuessGame>();
        game->Start();
        uploader.Upload(std::move(game));
    }
    return 0;
}
