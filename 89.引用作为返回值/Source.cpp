#include<iostream>
using namespace std;

//引用作为函数的返回值
//不要返回局部变量的引用！！！！

int& test()
{
	int a = 10;//局部变量
	return a;
}

int& test1() {
	static int a = 10;//全局区，程序结束之后释放
	return a;
}


int main()
{
	int& ref = test();
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;
	//也属于是微软编译器的特性！这个和局部变量的指针一致，微软编译器会保留

	int& ref1 = test1();
	cout << ref1 << endl;
	cout << ref1<< endl;


	//函数调用可以作为左值
	test1() = 1000;//!!!有点奇特！
	cout << ref1 << endl;
	cout << ref1 << endl;

}