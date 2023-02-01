#include<iostream>
using namespace std;


//函数的默认参数
int func(int a, int b, int c = 100) {
	return a + b + c;
}


//从某个参数开始有默认参数了，其后面的参数也必须有默认参数，否则会报错
//int func1(int a, int b = 10, int c) {}

//如果一个函数的声明有默认参数，它的实现就不能有默认了
//如果实现有了默认参数，那么它的声明就不能有默认了
int func2(int a = 20, int b = 100);

int func2(int a, int b) {
	return a * b;
}

int main()
{
	cout << func(1, 2) << endl;

	cout << func2() << endl;
}