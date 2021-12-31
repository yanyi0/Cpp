//
//  main.cpp
//  Mutex
//
//  Created by Cloud on 2021/12/25.
//

#include <iostream>
#include <thread>
void work1(int&sum){
    for (int i = 1; i < 5000; i++) {
        sum += i;
    }
}
void work2(int& sum) {
    for (int i = 5000; i <= 10000; i++) {
        sum += i;
    }
}
int fun() {
    int sum = 0;
    for (int i = 1; i <= 10000; i++) {
        sum += i;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int ans = 0;
    std::thread t1(work1, std::ref(ans));
    std::thread t2(work2, std::ref(ans));
    t1.join();
    t2.join();
    std::cout << "sum1 : " << ans << std::endl;
    std::cout << "sum2 : " << fun() << std::endl;
    return 0;
}
