#include<iostream>
using namespace std;

//静态成员变量
//所有对象共享同一份数据
//在编译阶段分配内存
//类内声明，类外初始化

//静态成员变量不属于某个对象上，所有对象共享一份数据
//两种访问方式
//通过对象访问
//通过类名进行访问

//静态成员变量也是有访问权限的


//静态成员函数
//1.所有对象共享同一个函数
//2.静态成员函数只能访问静态的成员变量



class Person
{
public:

	static void func() {
		cout << "static void func调用" << endl;
		m_A = 100;
		//nonstaticA = 100;//静态成员函数不能访问非静态成员变量
		//因为，非静态成员是隶属于具体的对象个体的，静态成员函数调用时无法区分非静态成员隶属于具体哪一个
	}


	static int m_A;
	int nonstaticA;
private:

	static void func2() {
		cout << "static void func2调用" << endl;
	}


	static int m_B;
};
//类外初始化
int Person::m_A=100;
int Person::m_B = 300;

void test() {
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p2.m_A << endl;

	cout << p.m_A << endl;

	//通过类名访问！
	cout<<Person::m_A << endl;


	//private的static成员变量类外是不可访问的
	//cout << Person::m_B << endl;
	//Person::func2();
}

void test2() {
	Person p;
	p.func();

	Person::func();
}




int main() {
	//test();
	test2();
}