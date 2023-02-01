#include<iostream>
using namespace std;

//继承中构造和析构的顺序
class Base {
public:
	Base() { cout << "Base的构造函数" << endl; }
	~Base()
	{
		cout << "Base的析构函数" << endl;
	}

};

class Son :public Base {
public:
	Son() { cout << "Son的构造函数" << endl; }
	~Son()
	{
		cout << "Son的析构函数" << endl;
	}
};

void test() {
	Son s;
}

/// <summary>
/// 构造顺序：父类->子类
/// 析构顺序：子类->父类
/// </summary>
/// <returns></returns>

int main() {
	test();
}