// std::atomic 用法與範例
// https://shengyu7697.github.io/std-atomic/

// g++ std-atomic.cpp -o a.out -std=c++11 -pthread
#include <iostream>
#include <thread>
#include <mutex>  // 使用 mutex 來確保同一時間內只有一個執行緒可以存取 cnt
#include <atomic> // atomic 達到同樣效果，時間約少了7倍，效能大爆發

using namespace std;

long cnt = 0;
std::mutex mtx;
std::atomic_long cnt_atomic(0);

void counter_original_error_version(){
    for (int i = 0; i < 100000; i++){
        cnt += 1;
    }
}

void counter_mutex()
{    
    for (int i = 0; i < 100000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        cnt += 1;
    }
}

void counter_atomic()
{
    for (int i = 0; i < 100000; i++) {
        cnt_atomic += 1;
    }
} 

int main(int argc, char* argv[])
{
    int mode = 2;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::thread threads[100];
    for (int i = 0; i != 100; i++)
    {
        if(mode == 0){
            threads[i] = std::thread(counter_original_error_version);
            // original result errot version (no use mutex and atomic_long):
            // result: 855684
            // duration: 37.52 ms
        }
        if(mode == 1){
            threads[i] = std::thread(counter_mutex);
            // mutex lock result correct version:
            // result: 10000000
            // duration: 809.167 ms
        }
        if(mode == 2){
            threads[i] = std::thread(counter_atomic);
            // Use atomic_long correct result:
            // result: 10000000
            // duration: 186.935 ms
        }
    }

    for (auto &th : threads)
        th.join();

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t2 - t1;

    std::cout << "mode: " << mode << std::endl;
    if(mode != 2){
        std::cout << "result: " << cnt << std::endl;
    }else{
        std::cout << "result: " << cnt_atomic << std::endl;
    }
    std::cout << "duration: " << elapsed.count() << " ms" << std::endl;
    return 0;
}




// g++ -c .\14.atomic_test.cpp;g++ -o 14.atomic_test.exe 14.atomic_test.o