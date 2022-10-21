// Reference: https://shengyu7697.github.io/cpp-memcmp/
// g++ -c 19.memcmp_test.cpp && g++ -o 19.memcmp_test.exe 19.memcmp_test.o

# include <iostream>
#include <cstring>

using namespace std;

// memcmp() 判斷兩段記憶體區塊內容相同的話會回傳 0
char memcmp_test(char *input_buffer1, char *input_buffer2){
    int ret = memcmp(input_buffer1, input_buffer2, sizeof(input_buffer1));

    if (ret > 0) {
        cout << "buffer1 is greater than buffer2" << endl;
    } else if (ret < 0) {
        cout << "buffer1 is less than buffer2" << endl;
    } else { // ret == 0
        cout << "buffer1 is equal to buffer2" << endl;
    }

    return 0;
}

int main()
{
    char buffer1[] = "abcde";
    char buffer2[] = "abcde";
    cout << "Input buffer1: " << buffer1 << endl;
    cout << "Input buffer2: " << buffer2 << endl << endl;

    cout << "result: " << memcmp_test(buffer1, buffer2) << endl;
    return 0;
}