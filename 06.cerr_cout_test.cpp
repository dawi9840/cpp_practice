 // iostream_cerr.cpp
// compile with: /EHsc
// By default, cerr and clog are the same as cout
#include <iostream>
#include <fstream>
 
using namespace std;
 
void TestWide() 
{
 int i = 0;
 wcout << L"Enter a number: ";
 wcin >> i;
 wcerr << L"test for wcerr" << endl;
 wclog << L"test for wclog" << endl; 
}
 
int main() 
{
 int i = 0;
 cout << "Enter a number: ";
 cin >> i;
 cerr << "test for cerr" << endl;
 clog << "test for clog" << endl;
//  TestWide();
}


/***
cerr可以把資料輸出到標準錯誤輸出裝置，其功能與cout輸出物件相近，cerr也需要搭配「<<」運算子，將資料輸出到標準錯誤輸出設備

cerr與cout的主要差別在於，cout會先將資料儲存到緩衝區（buffer）中，而cerr則是直接將資料輸出，如此雖然會增加I/O的操作次數，
減低程式的效率，但也使得程式設計師在程式開發除錯階段，能更即時的接收到適當的輸出結果。
// https://blog.xuite.net/cssuen/work/7450923
***/
 
// ------------------------------------------------------------------------------------
//  cerr:錯誤輸出流，無緩沖，不可以重定向。輸出的數據不經過緩沖區，直接放到指定的目標中，
//       既然不經過緩沖區那麽其它程序就無法把要輸出的內容送到其他目標中，所以說它不能被重定向。 

// cout:標準輸出流，有緩沖，可重定向。把要輸出的數據先放到緩沖區中，然後再從緩沖區到你指定的設備中。
//      當向cout流插入一個endl,不論緩沖區是否漫了,都立即輸出流中所有數據,然後插入一個換行符.
//  https://www.itread01.com/articles/1506204007.html
// ------------------------------------------------------------------------------------

