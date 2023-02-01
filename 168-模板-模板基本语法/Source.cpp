//函数模板
//
//template<typename T>
//template<class T>
//上面的typename和class可以互相替换

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;


//整型交换
//void Swap(int &a,int&b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////交换浮点类型
//void Swap(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//}

template<class T>//声明一个模板，告诉编译器后面的代码紧跟着T不要报错
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

void test() {
	int a = 10;
	int b = 20;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	Swap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;


	double c = 14;
	double d = 15;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	Swap(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d<< endl;

	//使用模板进行交换
	//自动类型推导
	Swap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	//
	Swap<int>(a, b);//显式告知T的类型
}


int main() {
	test();
}