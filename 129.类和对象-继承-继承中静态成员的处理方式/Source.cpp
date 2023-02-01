#include<iostream>
using namespace std;

class Base {
public:
	static int _a;

	static void Func() {
		cout << "Base Func" << endl;
	}
};
int Base::_a = 100;

class Son :public Base {
public:
	static int _a;
	static void Func() {
		cout << "Son Func" << endl;
	}
};
int Son::_a = 200;

void test01() {
	Son s;
	//1.ͨ�������������
	cout << "Son s._a= " << s._a << endl;
	cout << "Base s._a= " << s.Base::_a << endl;

	//2.ͨ�������Ʒ�������
	cout << "Son s._a= " << Son::_a<< endl;
	cout << "Base s._a= " << Son::Base::_a << endl;
}

void test02() {
	Son s;
	//1.ͨ��������ʺ���
	s.Func();
	s.Base::Func();
	//2.ͨ���������ʺ���
	Son::Func();
	Son::Base::Func();
}

int main() {
	test01();
	test02();
}

