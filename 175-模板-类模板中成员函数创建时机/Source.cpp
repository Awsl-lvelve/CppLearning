#include<iostream>
using namespace std;

//类模板中成员函数创建时机
//类模板中成员函数在调用时创建，类中成员函数在编译阶段创建

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