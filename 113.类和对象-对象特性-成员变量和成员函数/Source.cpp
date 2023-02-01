#include<iostream>
using namespace std;

//成员变量和成员函数分开存储

class Person
{
public:
	Person() = default;

	~Person()
	{
	}

	//静态成员函数也不属于对象
	static void func() {
		cout << "static void func" << endl;
	}

	//非静态成员函数不属于对象
	void func1() {
		cout << "nonstatic void func" << endl;
	}

private:
	int _age;//如果有一个成员，那么会占据4byte的空间
	static int m_b;//静态成员变量不属于特定对象，所以还是4

};
int Person::m_b = 10;

void test() {
	Person p;//空对象占用的内存空间为：1
	//c++编译器会对每个空对象分配一个字节的空间，是为了区分空对象占据内存的位置
	cout << "sizeof p = " << sizeof(p) << endl;



}

int main() {
	test();
}
