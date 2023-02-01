//引用相对来说是对指针传递参数的一种替换

#include<iostream>
using namespace std;

//会发生改变
void myswap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 11;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	myswap(a, b);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}