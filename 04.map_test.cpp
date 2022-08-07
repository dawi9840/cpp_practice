// g++ std-map2.cpp -o a.out -std=c++11
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, string> MMP;

int main() {
    cout << "map method1" << endl;
    map<int, string> studentMap = {
        {1, "Tom"},
        {3, "John"},
        {2, "Jack"}
    };
    studentMap[5] = "Tiffany";
    studentMap[4] = "Annccccc";

    // //只想讀取range中元素時，使用const auto&,
    // 如：for(const auto&x:range),它不會進行拷貝，也不會修改range 
    for (const auto& s : studentMap) {  
        cout << "id: " << s.first << ", name: " << s.second << "\n";
    }

    cout << "--------------------------" << endl;
    cout << "map method2" << endl;
    // map method2
    map<int, string> AA = MMP;
    AA[0] = "A001";
    AA[1] = "A002";
    AA[2] = "A003";

    for (const auto& ss : AA) {  
        cout << "id: " << ss.first << ", name: " << ss.second << "\n";
    }

    return 0;
}





// c++中的auto、const auto&: https://www.796t.com/content/1545629777.html
// https://shengyu7697.github.io/std-map/