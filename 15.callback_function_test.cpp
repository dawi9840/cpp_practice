// https://dangerlover9403.pixnet.net/blog/post/83880061-%5B%E6%95%99%E5%AD%B8%5Dc-c++-callback-function-%E7%94%A8%E6%B3%95-%E7%AF%84%E4%BE%8B-(%E5%85%A7%E5%90%ABfunctio

#include <iostream>

using namespace std;

typedef void (*FuncPtr)();

void function_A(){
    cout << "This is A function." << endl;
}

void function_B(){
    auto aa = "This is B function.";
    cout << aa << endl;
}

FuncPtr funs [] = {function_A, function_B};

void test_Fun_Ptr(){
    int mode;
    FuncPtr funptr;

    while(1){
        cout << "Please key the mode(1-A, 2-B):" << endl;
        scanf("%d", &mode);

        if( mode > 2 || mode == 0){
            break;
        }

        funptr = funs[mode - 1];
        funptr();
    }
}


int Add(int a, int b){
    return (a + b);
}

int Mul(int a, int b){
    return (a * b);
}

int main()
{
    cout << "callback method example1:" << endl;
    test_Fun_Ptr();

    cout << "------------------" << endl;
    int (*FunctionPointer)(int, int);
    int x = 3, y = 5;
    cout << "Input \nx: " << x << ", y: " << y << endl;
    FunctionPointer = Add;
    cout << "Add: " << FunctionPointer(x, y) << endl;

    FunctionPointer = Mul;
    cout << "multiply: " << FunctionPointer(x, y) << endl;

    return 0;
}

// g++ -c .\15.callback_function_test.cpp;g++ -o 15.callback_function_test.exe 15.callback_function_test.o