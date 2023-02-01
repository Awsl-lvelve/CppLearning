#include<iostream>
#include<string>

using namespace std;

//全局变量
int g_a = 10;

//全局常量
const int g_c_a = 100;

//在栈上
int* func() {
	int a = 10;
	return &a;
}
//在堆上
int* func1() {
	int *p=new int(10);//指针本身还是一个局部变量。但是它指向的数据在堆区
	return p;
}



int main() {
	////普通局部变量
	//int a = 10;
	//cout <<(int) & a << endl;
	//cout <<(int) & g_a << endl;
	////静态局部
	//static int s_a = 100;
	//cout << (int)&s_a << endl;
	////局部常量
	//const int c_a = 10;
	//cout << (int)&c_a << endl;
	//cout << (int)&g_c_a << endl;

	//int* p = func();//微软编译器似乎会保留返回的局部变量的地址，但是不建议这么干
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;
	
	int* p = func1();


	cout << *p << endl;
	cout << *p << endl;
}