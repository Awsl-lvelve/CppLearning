#include<iostream>
using namespace std;

//打印数据的函数
void ShowValue(const int& ref) {
	cout << ref << endl;
}


int main() {
	//常量引用，修饰形参，防止误操作
	int a = 10;
	
	//int& ref = 10;//这样是不行的
	const int& ref = 10;//这样是可以的
	//本质是 int temp=10； const int&ref=temp;
	//加上const就防止修改形参
	ShowValue(ref);
	

	


}