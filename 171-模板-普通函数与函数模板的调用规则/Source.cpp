#include<iostream>
using namespace std;

//如果普通和函数模板都可以调用，优先调用普通函数，
//但是可以使用空模板参数列表可以强制调用
//函数模板可以重载
//如果函数模板可以更好地匹配则优先调用函数模板

//如果写了模板，就不要用普通函数了

void myPrint(int a, int b) {
	cout << "MyPrintNormFunc" <<  endl;
}

template<class T >
void myPrint(T a, T b) {
	cout << "MyPrintTemplateFunc" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "MyPrintTemplateFuncReload" << endl;
}

template<class T1,class T2>
void myPrint(T1 a, T2 b) {
	cout << "MultiTypeMyPrintTemplateFuncReload" << endl;
}

void test1() {
	int a = 10;
	int b = 20;
	//优先调用普通函数
	myPrint(a, b);
	//强制调用
	myPrint<>(a, b);
	//模板重载
	myPrint(1, 2, 3);
	//更好的匹配
	myPrint('a', 'b');
}




int main() {
	test1();
	return 0;
}