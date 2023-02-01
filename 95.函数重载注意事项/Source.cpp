#include<iostream>
using namespace std;

//函数重载遇到默认参数
//引用可以作为重载的条件

void func(int& a) {
	cout << "func(int&a)" << endl;
}

void func(const int& a) {
	cout << "func(const int&a)" << endl;
}

//默认参数不能作为重载条件会引发冲突
// 传一个参数会出问题，会出现二义性，传两个不会出问题，不会出现二义性
//void func(int a,int b=10) {
//	cout << "func(int a,int b=default)" << endl;
//}



int main()
{
	int a = 10;
	func(a);//调用上面的

	const int b = 10;
	func(b);//调用下面的
	func(20);//调用下面的

}