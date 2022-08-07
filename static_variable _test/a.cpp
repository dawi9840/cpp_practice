#include <iostream>
using namespace std;

static bool debug = true;

void show_debug_in_a() {
    string status = "";
    if (debug == true){
        status = "true";
    }else{
        status = "false";
    }
    cout << "show_debug_in_a: " << status << endl;
}