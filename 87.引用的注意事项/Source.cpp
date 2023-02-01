#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;//必须初始化！

	int c = 122;
	b = c;//这里只是赋值操作
	//在初始化之后就不准改了
}