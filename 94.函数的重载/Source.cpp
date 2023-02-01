#include<iostream>
using namespace std;

//条件
///同一个作用域
//函数名相同
//函数参数的类型、数量或者二者都不同

//函数的返回值不允许发生重载！！！

void func(int a, int b, int c) {
	cout << a + b + c<<"i"<<endl;
}

void func(int a, int b, int c,int d) {
	cout << a + b + c + d <<"j"<< endl;
}

void func(double a, int b, int c) {
	cout << a + b + c <<"k"<< endl;;
}

int main() {
	func(1, 2, 3);
	func(1, 2, 3, 4);
	func(1.0, 20.0, 10);
}