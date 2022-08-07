// g++ -c main.cpp
// g++ -c module1.cpp
// g++ -o main.exe main.o module1.o
// https://medium.com/@alan81920/c-c-%E4%B8%AD%E7%9A%84-static-extern-%E7%9A%84%E8%AE%8A%E6%95%B8-9b42d000688f

#include <iostream>
#include "module1.h"

using namespace std;

int main() {
    greeting();
    cout << "++++++++++++++++++++++++" << endl << endl;

    cout << "In main, a = " << a << endl;

    cout << "-------------------------" << endl << endl;
    a = 0;
    cout << "In main, a = " << a << endl;

    cout << "**************************" << endl << endl;
    return 0;
}