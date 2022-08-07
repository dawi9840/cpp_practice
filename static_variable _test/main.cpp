// C/C++ 中的 static, extern 的變數
// https://medium.com/@alan81920/c-c-%E4%B8%AD%E7%9A%84-static-extern-%E7%9A%84%E8%AE%8A%E6%95%B8-9b42d000688f

#include "./head_file/a.h"
#include "./head_file/b.h"

int main() {

    show_debug_in_a();
    show_debug_in_b();
    return 0;

}

// 然後可以 compile 成 bin 檔：
// 產出 main.o
// $ g++ -c main.cpp 

// 產出 a.o
// $ g++ -c a.cpp 

// 產出 b.o
// $ g++ -c b.cpp 

// 把 main.o, a.o, b.o link 成 main
// $ g++ -o main.exe main.o a.o b.o 