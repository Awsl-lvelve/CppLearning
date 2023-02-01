#include<iostream>
using namespace std;

//引用传递，会改变原值，不是拷贝
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//值传递，不会改变原值，只会拷贝一份
void Swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	Swap1(a, b);
	cout << a << " " << b << endl;
}