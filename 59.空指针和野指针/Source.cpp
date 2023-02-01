#include<iostream>
using namespace std;

//空指针
//用途：初始化指针变量
//注意：空指针指向的内存不可访问


int main() {
	//1.空指针可以给指针变量初始化
	int* p = nullptr;
	//2.不可访问
	//*p = 100;
	//cout << *p << endl;

	//野指针：指向非法的内存空间
	int* p1 = (int*)0x1100;
	cout << *p1 << endl;
	//编译器不检查这个错误，但是会有问题


}