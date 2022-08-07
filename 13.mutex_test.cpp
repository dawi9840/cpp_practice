// std::mutex 用法與範例
// https://shengyu7697.github.io/std-mutex/
// std::mutex 算是多執行緒中常用到的基本功能，mutex 用來上鎖一段多執行緒會交互存取的程式區塊，
// 確保同一時間內只有一個執行緒能夠存取這段程式區塊，避免程式發生不預期的意外狀況。
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex g_mutex;
int g_count = 0;

// 使用 g_mutex.lock() 手動上鎖，使用 g_mutex.unlock() 手動解鎖。
int print(int n, char c) {
    // critical section (exclusive access to std::cout signaled by locking mtx):
    // 臨界區（通過鎖定 mtx 表示對 std::cout 的獨占訪問）：
    g_mutex.lock();
    for (int i = 0; i < n; ++i) {
        std::cout << c;
        g_count++;
    }
    std::cout << '\n';
    std::cout << "count=" << g_count << std::endl;
    g_mutex.unlock();
}

//  std::mutex 的成員函式 lock/unlock 來上鎖是可以的，只是要注意 lock 要有對應的 unlock ，一旦沒有解鎖到程式很可能就會發生死鎖。
// 配合 std::lock_guard 使用，學會用 std::lock_guard 就可以避免手動上鎖解鎖，進而減少在寫程式上出現死鎖的機會。
int print2(int n, char c) {
    // lock_guard 建構時對 mutex 上鎖，解構時對 mutex 解鎖，
    // lock_guard 利用生命週期概念來進行上鎖與解鎖，lock_guard 本身並不管理 mutex 的生命週期，
    // 也就是 lock_guard 生命週期結束不代表 mutex 生命週期也結束。
    // critical section (exclusive access to std::cout signaled by locking mtx):
    // 臨界區（通過鎖定 mtx 表示對 std::cout 的獨占訪問）：
    std::lock_guard<std::mutex> lock(g_mutex);
    for (int i = 0; i < n; ++i) {
        std::cout << c;
        g_count++;
    }
    std::cout << '\n';

    std::cout << "count=" << g_count << std::endl;
}

//  多執行緒呼叫同一個函式(有 mutex 鎖)
void mutex_test1(){
    std::thread t1(print, 10, 'A');
    std::thread t2(print, 5, 'B');
    t1.join();
    t2.join();
}

// 使用 lock_guard 來上鎖與解鎖
void mutex_test2(){
    std::thread t1(print2, 10, 'C');
    std::thread t2(print2, 5, 'D');
    t1.join();
    t2.join();
}

int main() 
{
    cout << "mutex_test1:" << endl;
    mutex_test1();
    cout << endl << "mutex_test2:" << endl;
    mutex_test2();

    return 0;
}