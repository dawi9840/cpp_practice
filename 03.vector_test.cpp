#include <iostream>
#include <vector>

using namespace std;

vector<int> vector_test1(vector<int> vec){
    return vec;
}

int main() {
    vector<int> bb =  vector_test1({1, 2, 3, 4, 5, 6});
    cout << "Vector Result: " << endl << endl;
    for (int i = 0; i < bb.size(); i++) {
        cout << "bb["<< i << "]: " << bb[i] << endl;
    }
    return 0;
}





// Reference: https://shengyu7697.github.io/std-vector/
