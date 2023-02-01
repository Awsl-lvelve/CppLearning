#include<iostream>
#include<string>
using namespace std;

//对于内置的数据类型，编译器指导如何计算

//对于内置数据类型，是不允许重载的

class Person {

public:
	//成员函数重载
	//Person& operator+(Person & rhs)
	//{
	//	this->_A += rhs._A;
	//	this->_B += rhs._B;
	//	return *this;
	//}
public:
	int _A;
	int _B;
};

//全局函数重载+
Person& operator+(Person& p1, Person& p2) {
	Person temp;
	temp._A = p1._A + p2._A;
	temp._B = p1._B + p2._B;
	return temp;
}

void test() {
	Person p1;
	p1._A = 10;
	p1._B = 10;

	Person p2;
	p2._A = 100;
	p2._B = 100;

	Person p3 = p1 + p2+p2+p2+p1;
	cout << p3._A << endl;
	cout << p3._B << endl;

}

int main() {
	test();
}