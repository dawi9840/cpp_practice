// C/C++ strcat 用法與範例
// https://shengyu7697.github.io/cpp-strcat/
// memset : https://shengyu7697.github.io/cpp-memset/

// g++ strcat_test.cpp -o strcat_test.out
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//  memset 來對一段記憶體區塊全部設定為某個值，通常設為 0，要使用 memset 的話需要引入的標頭檔 <string.h>，如果要使用 C++ 的標頭檔則是引入 <cstring>。
// memset() 將 ptr 指向的記憶體區塊全部設定成 value，num 為設定的數量，
// memset 一般用來初始化字串全部設成 \0 字元，來看看下面的 memset 用法範例吧！
void memset_test(){
    std::cout << "memset usage result:" << std::endl;
    char str1[32] = "hello world";

    memset(str1, '\0', sizeof(str1)); // or memset(str1, 0, 32);
    printf("str1: %s\n", str1);
    std::cout << "sizeof(str1): " << sizeof(str1) << endl;

    printf("####################\n\n");

    char str2[] = "hello world";    
    memset(str2, 'a', 3);
    printf("str2: %s\n", str2);

    printf("----------------\n\n");
    char str3[] = "hello world";    
    memset(str3+5, 0, 6);
    printf("str3: %s\n\n", str3);
}

// C/C++ 要連接 c-style 字串可以使用 strcat 來完成，要使用 strcat 的話需要引入的標頭檔 <string.h>，如果要使用 C++ 的標頭檔則是引入 <cstring>。
void strcat_test(){
    std::cout << "strcat usage result:" << std::endl;
    const char *str1 = "hello";
    const char *str2 = "world";
    char dest[64];
    
    memset(dest, 0, sizeof(dest)); // memset 是用來對一段記憶體區塊全部設定為某個值的函式
    strcat(dest, str1);
    strcat(dest, " ");
    strcat(dest, str2);
    strcat(dest, " ^_^");
    printf("dest: %s\n\n", dest);
}

int main() {
    memset_test();
    strcat_test();
    return 0;
}