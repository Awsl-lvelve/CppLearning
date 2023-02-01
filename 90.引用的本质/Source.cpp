#include<iostream>
using namespace std;

//引用的本质：指针常量

void func(int& ref) {
	ref = 1001;
}

int main() {
	int a = 100;

	int* const pa = &a;
	//等价于
	int& ref = a;

	cout << "adress a: " << (int)&a << endl;
	cout << "pa: " << *pa << endl;
	cout << "adress pa: " << (int)&pa << endl;
	cout << "ref: " << a << endl;
	cout << "adress ref: " << (int) & ref << endl;

	func(ref);
	cout << "adress a: " << (int)&a << endl;
	cout << "pa: " << *pa << endl;
	cout << "adress pa: " << (int)&pa << endl;
	cout << "ref: " << a << endl;
	cout << "adress ref: " << (int)&ref << endl;

}
