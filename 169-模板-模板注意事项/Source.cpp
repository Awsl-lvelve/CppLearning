#include<iostream>
using namespace std;

//函数模板
//1.自动类型推导，必须导出一致的数据类型
//2.模板必须要确定T的数据类型才能使用

template<class T>
void MySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void Func() { cout << "Func调用" << endl; }

void test01() {
	int a = 10;
	int b = 20;

	MySwap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	char c = 11;
	//MySwap(a, c);
	//cout << "a=" << a << endl;
	//cout << "c=" << b << endl;
	//推导出不一致的T类型的参数
}

void test02() {
	//Func();//不确定数据类型，会报错
	Func<int>();//显式指定T类型，可以调用代码
}

int main() {
	test01();
	test02();
}