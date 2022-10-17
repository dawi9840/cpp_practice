// break、continue、goto
// https://openhome.cc/Gossip/CppGossip/breakContinueGoto.html
#include <iostream>

using namespace std;

int break_test(int intput_number, int start_value, int limit_number){
    cout << "intput_num: " << intput_number << endl;
    cout << "i: ";
    for(intput_number = start_value; intput_number < 100; intput_number++) {
        if(intput_number == limit_number) {
            break;
        }
        cout << intput_number << ", ";
    }
    return  intput_number;
}

int continue_test(int intput_number, int start_value, int limit_number){
    cout << "intput_num: " << intput_number << endl;
    cout << "i: ";
    for(intput_number = start_value; intput_number < 100; intput_number++) {
        if(intput_number == limit_number) {
            continue;
        }
        cout << intput_number << ", ";
    }
    return  intput_number;
}

int goto_test(){

BEGIN_label: 
    int intput_number, result; 
    cout << "Input a number: "; 
    cin >> intput_number;
    
    if(intput_number == 0) {
        goto ERROR_label; 
    }

    result = 100.0 / intput_number; 

    cout << "100 / " << intput_number 
         << " = " << result
         << endl;

    return result; 

ERROR_label: 
    cout << "Divisor cannot be 0" << endl; 
    cout << "Please input a valid number again!" << endl; 
    goto BEGIN_label;

}

int do_while_test(){
    // Modify goto usage, suggest use do while().
    int intput_number, result;
    result = 100.0 / intput_number; 
    
    do{
        cout << "Input a number: "; 
        cin >> intput_number;
        if(intput_number)
        {
            cout << "100 / " << intput_number 
                << " = " << result
                << endl; 
            break;
        }

    }while (true);

    return result;
}

int main(void)
{
    int intput_num = 20;
    int result;

    result = break_test(intput_num, 25, 30);
    cout << "break result: " << result << endl << endl;

    result = continue_test(intput_num, 25, 30);
    cout << "continue result: " << result << endl << endl;

    result = goto_test();
    cout << "goto result: " << result << endl << endl;

    result = do_while_test();
    cout << "do while result: " << result << endl << endl;

    return 0;
}

// g++ -c ./17.break_continue_goto.cpp
// g++ -o 17.break_continue_goto.exe 17.break_continue_goto.o