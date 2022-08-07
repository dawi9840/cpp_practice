// std::condition_variable 用法與範例
// https://shengyu7697.github.io/std-condition_variable/
// g++ condition_variable_test.cpp -o a.out -std=c++11 -pthread

// 使用 std::condition_variable 的 wait 會把目前的執行緒 thread 停下來並且等候事件通知，
// 而在另外一個執行緒裡我們可以使用 std::condition_variable 的 notify_one 或 notify_all 去發送
// 通知那些正在等待的事件，這在多執行绪程式裡經常使用到。
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cond_var;
bool ready = false;


void commonly_member_functions_and_descriptions()
{
    /**
        以下為 condition_variable 常用的成員函式與說明，
        wait：阻塞當前執行緒直到條件變量被喚醒
        notify_one：通知一個正在等待的執行緒
        notify_all：通知所有正在等待的執行緒
    **/
    // 使用 std::condition_variable 的 wait 必須要搭配 std::unique_lock<std::mutex> 一起使用。
}


// 開一個新的執行緒 worker_thread 然後使用 std::condition_variable 的 wait 事件的通知
void worker_thread()
{
    std::unique_lock<std::mutex> lock(m); // 此時 worker_thread 會阻塞(block)直到事件通知才會被喚醒，
    std::cout << "worker_thread(): wait\n";
    cond_var.wait(lock);

    // after the wait, we own the lock.
    std::cout << "worker_thread() is processing data\n";
}


void print_id(int id) {
    std::unique_lock<std::mutex> lock(m);
    while (!ready) {
        cond_var.wait(lock);
    }
    std::cout << "thread: " << id << '\n';
}


void go() {
    std::unique_lock<std::mutex> lock(m);
    ready = true;
    cond_var.notify_all(); // 通知所有正在等待的執行緒
}


// Example1.用 notify_one 通知一個正在 wait 的執行緒
void notify_one_test(){
    std::thread worker(worker_thread);
    //遲個 5 ms 在使用 std::condition_variable 的 notify_one 發送，延遲 5ms 是避免一開始執行緒還沒建立好來不及 wait 等待通知，主程式就先發送 notify_one 事件通知了
    // // 之後 worker_thread 收到 來自主執行緒的事件通知就離開 wait 繼續往下 cout 完就結束該執行緒。
    std::this_thread::sleep_for(std::chrono::milliseconds(5)); 
    std::cout << "main() notify_one\n"; 

    cond_var.notify_one();  
    worker.join();   

    std::cout << "main() end\n"; 
}


// Example2.用 notify_all 通知全部多個 wait 等待的執行緒
void notify_all_test(){
    // 建立5個執行緒並等待通知，
    // 主程式執行go函式裡的cond_var.notify_all()去通知所有正在等待的執行緒(剛剛建立的5個執行緒)，
    // 這5個執行緒分別收到通知後從wait函式離開，之後檢查ready變數為true就離開迴圈。
    std::thread threads[5];
    // spawn 5 threads: (產生 5 個線程)
    for (int i=0; i<5; ++i)
        threads[i] = std::thread(print_id, i);

    std::cout << "5 threads ready to race...\n";
    go();

    for (auto& th : threads)
        th.join();
}

// Example3.wait 等待通知且有條件式地結束等待

int main()
{
    std::cout << "\nnotify_one_test:\n";
    notify_one_test();

    std::cout << "\nnotify_all_test:\n";
    notify_all_test(); //可以看見這5個執行緒不按順序地收到通知並且各別印出thread id
}