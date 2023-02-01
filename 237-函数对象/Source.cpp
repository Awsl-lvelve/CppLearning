#include<iostream>
using namespace std;

//函数对象（仿函数）
//函数对象在使用时，可以像普通函数那样调用，也可以有参数，可以有返回值
//函数对象超越了普通函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递

class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};


//函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01() {
	MyAdd myadd;
	cout << myadd(10, 10)<<endl;
}


class MyPrint {
public:
	void operator()(string test) {
		cout << test << endl;
		this->count_++;
	}
	MyPrint(int count):count_(count) {}
	MyPrint() { this->count_ = 0; }

	int count_;
};

void test02() {
	MyPrint print;
	print("Hello World");
	print("AnyThingPls");
	print("Whatever");
	cout << "调用次数:" << print.count_ << endl;
}

//函数对象作为参数传递
void doPrint(MyPrint& print, string test) {
	print(test);
}

void test03() {
	MyPrint pt;
	string  str= "Say hello!";
	doPrint(pt, str);

}

int main() {
	//test01();
	//test02();
	test03();
}
