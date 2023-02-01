#include<iostream>
using namespace std;

int main() {
	int a = 100;
	int b = 1000;
	const int* p = &a;
	//指针指向的值不允许改
	//*p = 1000;
	
	//指针的指向可以改
	cout << "原来指针指向的空间的内容" << endl;
	cout << *p << endl;
	cout << "现在指针指向的空间的内容" << endl;
	p = &b;
	cout<<*p;

	int c = 99;
	int d = 89;
	int* const p1 = &c;
	//指针的指向不准改
	//p1 = &d;
	//但是指向的值可以改
	*p1 = 999;

	int e = 133;
	int f = 22;
	const int* const p2 = &e;
	//指向的方向不能改
	//p2 = &f;
	
	//指向的方向对应的内容也不能改
	//*p2 = 111;
}