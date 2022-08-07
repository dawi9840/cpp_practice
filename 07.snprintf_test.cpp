// https://shengyu7697.github.io/cpp-snprintf/
// C/C++ snprintf 格式化輸出基本用法
// g++ snprintf_test.cpp -o snprintf_test.out

// snprintf 函式會在中將格式化輸出的一連串字元存到 buffer 裡。
// 隨後的每個引數 argument 是根據 format 中的對應格式進行轉換和輸出。
#include <iostream>
#include <stdio.h>
#include <string.h>


// 例如將數字格式化輸出成字串到 buffer 裡、將浮點數格式化輸出成字串到 buffer 裡。
void snprintf_example1(){
    char buf[128] = {0};
    const char str[] = "Hello world";
    char c = 'a';
    int num = 123;
    float f = 5.4321f;

    snprintf(buf, 128, "string: %s\n", str);
    printf("%s", buf);

    snprintf(buf, 128, "character: %c\n", c);
    printf("%s", buf);

    snprintf(buf, 128, "integer: %d\n", num);
    printf("%s", buf);

    snprintf(buf, 128, "float: %f\n", f);
    printf("%s", buf);
}

/** 有時需要將一些資料格式化輸出並且連接在一起，
        這時可以使用 snprintf 搭配 strcat，
        snprintf 將資料格式化輸出到 tmp 後，
        再使用 strcat 連接 tmp 到 buf 裡，最後再用 printf 輸出結果。 */
void snprintf_example2(){
    char hex[] = {0x01, 0x02, 0x03, 0x1a, 0x2b, 0x3c}; // 01, 02, 3, 26, 43, 60
    // 十六進制 0~f 對應 十進制 0~15，0x01就是1，0x0a就是10
    char tmp[128] = {0};
    char buf[128] = {0};

    for (int i = 0; i < sizeof(hex); i++) {
        snprintf(tmp, sizeof(tmp), "0x%02x, ", hex[i]);
        strcat(buf, tmp); // strcat 是用來連接兩個字串，或相加兩個字串的函式。
    }
    printf("hex : %s\n", buf);
}

int main() {
    std::cout << "snprintf: [example 1]" << std::endl;
    std::cout << "------------------" << std::endl;
    snprintf_example1();
    std::cout << std::endl << "snprintf: [example 2]" << std::endl;
    std::cout << "------------------" << std::endl;
    snprintf_example2();
    return 0;
}