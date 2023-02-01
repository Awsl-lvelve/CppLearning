//访问子类同名成员-直接访问即可
//访问父类同名成员-需要添加作用域

#include<iostream>
using namespace std;

class Base {
public:
	Base() {
		this->m_A = 100;
	}

	void Func() {
		cout << "Base Func调用" << endl;
	}
	void Func(int a) {
		cout << "Base Func(int)调用" << endl;
	}



	int m_A;
};

class Son :public Base {
public:
	Son() {
		this->m_A=200;
	}

	void Func() {
		cout << "Son Func调用" << endl;
	}
	void Func(int a) {
		cout << "Son Func(int)调用" << endl;
	}


	int m_A;
};

void test1() {
	Son s;
	cout << "Son 的m_A=" << s.m_A << endl;
	//同名成员的处理！
	cout << "继承下来的m_A=" << s.Base::m_A << endl;
}

void test2() {
	Son s;
	s.Func();
	s.Base::Func();

	//如果不注释掉子类中的func，子类的同名成员函数会
	//隐藏掉父类中所有同名成员函数
	//如果想要访问父类中被隐藏的，需要添加作用域
	s.Func(100);
	s.Base::Func(100);
}

int main() {
	test1();
	test2();
}
