#include<iostream>
using namespace std;

int main() {
	int a = 100;
	double b = 90;

	int* pa = &a;
	double* pb = &b;
	//int* 类型指针的占用空间
	cout << sizeof(pa) << endl;
	//double* 类型指针的占用空间
	cout << sizeof(pb) << endl;

	//32bit系统下，指针大小为4Byte
	//64bit系统下，指针大小为8Byte

}