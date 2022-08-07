// 如何在 C++ 中實現毫秒級的睡眠
// https://www.delftstack.com/zh-tw/howto/cpp/how-to-use-sleep-program-function-in-cpp/
// 這個方法是 <thread> 庫中 sleep 函式的純 C++ 版本，它是 Windows 和 Unix 平臺的可移植版本。
// 為了更好地演示示例，我們暫停程序 3000 毫秒。

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;

constexpr int TIME_TO_SLEEP = 3000; // 3000 毫秒。

int main() {
    cout << "Started loop.." << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Iteration i: " << i << endl;

        if (i == 4) {
            cout << "is sleeping 3000 ms ...." << endl;
            sleep_for(std::chrono::milliseconds(TIME_TO_SLEEP));
        }
    }
    return 0;
}