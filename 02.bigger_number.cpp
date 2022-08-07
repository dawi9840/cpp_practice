#include <iostream>
#include <string>
using namespace std;

// 宣告函數的函數原型
int big(int, int); 
int dataTypeTest(int);

int main(){
    // dataTypeTest(1234567);
    int input1 = 12;
    int input2 = 33;
    cout << "The biggest number: " << big(input1, input2) << endl << endl;
    return 0;
}

int dataTypeTest(int input_a){
    // data Type
    /*int 7. 89, -9, -9768, 0, 10 
    float 7.0, -9.8
    bool true, false
    string "I am a string!"
    char 'x', '0', 's'
    */

    // Variables
    // cout<< "Variable is: "<< input_a;
    cout << "Variable is: "<< input_a << endl << endl;
    return input_a;

}

int big(int a, int b) {  // 函數 big() 的實際定義
    // cout << endl << "Input number1:" << a << ", ";
    // cout << "Input number2:" << b << endl << endl;
    cout << endl << "Input number1: " << a << endl;
    cout << "Input number2: " << b << endl;
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}