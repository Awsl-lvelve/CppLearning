#include<iostream>
using namespace std;

//函数调用运算符的重载
//由于重载后使用的方式非常像函数的调用，因此成为仿函数
//仿函数没有固定写法，非常灵活

class MyPrint
{
public:
	void operator()(string text) {
		cout << text << endl;
	}
};

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void MyPrint2(string str) {
	cout << str << endl;
}

void test01() {
	MyPrint myprint;
	myprint("Hello World");
	MyPrint2("hELLO WORLD");
}

void test02() {
	MyAdd myadd;
	cout << myadd(1, 2) << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
};

int main() {
	test01();
	test02();
}