#include<iostream>
using namespace std;

//��ģ���г�Ա��������ʱ��
//��ģ���г�Ա�����ڵ���ʱ���������г�Ա�����ڱ���׶δ���

class Person1 {
public:
	void showPerson1() {
		cout << "Person1 Show" << endl;
	}
};

class Person2 {
public :
	void showPerson2() {
		cout << "Person2 Show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	void func1() {
		obj.showPerson1();
	};

	void func2() {
		obj.showPerson2();
	}

};

void test01() {
	MyClass<Person1> cls;
	cls.func1();
	//cls.func2();
}
int main() {
	test01();
}