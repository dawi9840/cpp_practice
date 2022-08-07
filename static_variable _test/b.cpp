#include <iostream>
using namespace std;

static bool debug = false;

void show_debug_in_b() {
    string status = "";
    if (debug == false){
        status = "false";
    }else{
        status = "true";
    }
    cout << "show_debug_in_b: " << status << endl;
}