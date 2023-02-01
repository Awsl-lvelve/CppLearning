#include<iostream>
using namespace std;

//引用：给变量起别名

int main()
{
	int a = 10;
	int& b = a;//这样定义了一个引用

	//指向的是同一块内存
	cout << (int)&a << endl;
	cout << (int)&b << endl;

	//对a的修改，也是对b的修改
}