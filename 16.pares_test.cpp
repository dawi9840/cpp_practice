#include <iostream>
#include <string>

using namespace std;

static int parseOpts(string input_str, string delimiter) {
    int rc = 0;
    int c;
    cout << "input string: " << input_str << endl;
    size_t pos = 0;
    std::string token;
    while ((pos = input_str.find(delimiter)) != std::string::npos) {
        token = input_str.substr(0, pos);
        cout << "token: " << token << endl;
        if (token == "m"){
            cout << token << " mode" << endl;
        }
        if (token == "p"){
           cout << token << " Broadcast port used, default to 5000." << endl;
        }
        if (token == "s"){
            cout << token << " Broadcast service Id, default to 1" << endl;
        }
        if (token == "l"){
            cout << token << "Unicast packet length, default to 256 Bytes" << endl;
        }
        if(token == "?"){
            rc = -1;
            cout << "Usage: "  << "\n"
                 << "-m<Mode>                  0--OBU 1--RSU, default to OBU\n"
                 << "-s<Broadcast Service Id>  Broadcast service Id, default to 1\n"
                 << "-p<Broadcast Port>  Broadcast port used, default to 5000\n"
                 << "-l<Unicast packet length>  default to 256 Bytes" << endl;
            return rc;
        }
        input_str.erase(0, pos + delimiter.length());
    }
    cout << "last one option:" << endl;
    cout << input_str << endl;

    return rc;
}

void split_string_test(string input_str, string delimiter){
    // delimiter : Can define yourself of specific delimiter.
    // Input: split_string_test("Y o o", " ");
    // Output: 
    // Y
    // o
    // o
    
    cout << "input string: " << input_str << endl;
    size_t pos = 0;
    std::string token;
    cout << "result: " << endl;
    char sstr[1000];

    while ((pos = input_str.find(delimiter)) != std::string::npos) {
        token = input_str.substr(0, pos);
        std::cout << token << std::endl;
        input_str.erase(0, pos + delimiter.length());
    }
    std::cout << input_str << std::endl;
}

int main(void)// argc表示參數的個數，argv[]表示每個參數字符串
{
    string str;
    cin >> str;
    // usage input: m_number, s_number, p_number, l_number.
    parseOpts(str, "_");
}


// g++ -c .\16.pares_test.cpp;g++ -o 16.pares_test.exe 16.pares_test.o