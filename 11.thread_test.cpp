// C++ std::thread 建立多執行緒用法與範例: https://shengyu7697.github.io/std-thread/
#include <iostream>
#include <thread>

using std::cout;
using std::endl;

// 呼叫 thread 建構子時會立即同時地開始執行這個新建立的執行緒，之後 main() 的主執行緒也會繼續執行，基本上這就是一個基本的建立執行緒的功能了。
void myfunc() {
    std::cout << "myfunc: print my_function.\n" << std::endl;
    // do something ...

    // "std::thread 常用的成員函式"
    // get_id(): 取得目前的執行緒的 id，回傳一個為 std::thread::id 的類型。
    // joinable(): 檢查是否可join。
    // join(): 等待執行緒完成。
    // detach(): 與該執行緒分離，一旦該執行緒執行完後它所分配的資源會被釋放。
    // native_handle(): 取得平台原生的native handle (例如Win32的Handle, unix的pthread_t)。

    // 其他相關的常用函式有，
    // sleep_for(): 停止目前執行緒一段指定的時間。
    // yield(): 暫時放棄CPU一段時間，讓給其它執行緒。
}

void foo() {
    std::cout << "print foo" << endl;
}

void bar(int x) {
    std::cout << "print bar\n";
}

void thread_test1(){
    cout << "this is thread_test1: \n";
    cout << "------------------------------" << endl;
    std::thread my_thead1(myfunc);
    my_thead1.join();
}

void thread_test2(){
    cout << "this is thread_test2: \n";
    cout << "------------------------------" << endl;
    std::thread t1(foo);     // 建立一個新執行緒且執行 foo 函式
    std::thread t2(bar, 0);  // 建立一個新執行緒且執行 bar 函式
    
    std::cout << "main, foo and bar now execute concurrently...\n"; // synchronize threads

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "sleep 1s\n";
    
    std::cout << "join t1\n";
    t1.join();                // 等待 t1 執行緒結束
    std::cout << "join t2\n";
    t2.join();                // 等待 t2 執行緒結束

    std::cout << "foo and bar completed!\n";
}

// 建立新 thread 來執行一個類別函式
class AA {
public:
    void a1() {
        std::cout << "a1\n";
    }

    void a2(int n) {
        std::cout << "a2: " << n << "\n";
    }

    void start() {
        std::thread t1(&AA::a1, this);
        std::thread t2(&AA::a2, this, 10);

        t1.join();
        t2.join();
    }
};

void thread_test3(){
    cout << "\nthis is thread_test3: \n";
    cout << "------------------------------" << endl;
    AA a;
    a.start();
}

int main() {
    thread_test1();
    thread_test2();
    thread_test3();
    return 0;
}