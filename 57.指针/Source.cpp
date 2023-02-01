#include<iostream>

using namespace std;

int main() {
	int a = 100;
	int b = 90;

	//指针的使用
	int* pa = &a;
	int* pb = &b;

	//*pointer 解引用操作 获得地址中存储的地址

	cout << *pa + *pb << endl;
}