// https://blog.csdn.net/qq_21989927/article/details/109989495?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165965900816781683965281%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165965900816781683965281&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-3-109989495-null-null.142^v39^pc_rank_v36&utm_term=protected%20c%2B%2B&spm=1018.2226.3001.4187
// 使用 protected 時，我們被允許可以在繼承的函數中修改成員的值。

#include<iostream>
using namespace std;
 
class Base{
	public:
        int a = 123;
        string aa = "Base_public_aa";

	protected:
        int b = 66;
        string bb = "Base_protected_bb";

	private:
        int c;
        string cc = "Base_private_cc";
};
 
class son:public Base{
	void show(){
		cout<< "public: " << a << endl;       // 可訪問 public 權限
        cout<< "public: " << aa << endl;      // 可訪問 public 權限
		cout<< "protected: " << b << endl;    // 可訪問 protected 權限
        cout<< "protected: " << bb << endl;   // 可訪問 protected 權限
		//cout<< "private: " << c <<endl;     // 不可訪問  private 權限
	}
};
 
int main() {
	son A;
	cout<<A.a<<endl;      //對象可以訪問public成員
    cout<<A.aa<<endl;     //對象可以訪問public成員

	// cout<<A.b<<endl;   //protected 無法訪問
    // cout<<A.bb<<endl;  //protected 無法訪問
	return 0;
}