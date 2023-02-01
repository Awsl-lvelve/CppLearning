#include<iostream>
using namespace std;

class Base1 {
public :
	Base1() {
		this->_A = 100;
	}
	int _A;

};

class Base2 {
public:
	Base2() {
		this->_B = 200;
	}

	int _B;
};

class Son :public Base1, public Base2 {
public:
	int _C;
	int _D;

	Son() {
		this->_C = 300;
		this->_D = 400;
	}
};

void test01() {
	Son s;
	cout << "sizeof son is "<<sizeof(s) << endl;
	cout << s.Base1::_A << endl;
	cout << s.Base2::_B << endl;
}

int main() {
	test01();
}

