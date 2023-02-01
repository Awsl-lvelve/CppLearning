#include<iostream>
using namespace std;

//模板局限性
//模板并不是万能地，有些特定的数据类型，需要具体化的方式进行实现
//自定义类型！！！

//对比两个数字是否相等
template<class T>
bool Comp(T& a,T& b) {
	if (a==b)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void test01() {
	int a = 10;
	int b = 10;

	bool ret = Comp(a, b);
	if (ret)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

class Person {
public:
	std::string m_name;
	int m_age;

	Person(std::string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	bool operator==(Person& p) {
		if (this->m_age==p.m_age&&this->m_name==p.m_name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//利用具体化的Person的版本实现Comp
template<> bool Comp(Person& a, Person& b) {
	cout << "如果用模板具体化Comp了会走哪？" << endl;
	//会走这个，而不会走运算符重载
	//如果把这个具体化的Comp注释了，就会走运算符重载
	if (a.m_name == b.m_name && a.m_age == b.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void test02() {
	Person p1("Tom",18);
	Person p2("Tom", 199);
	bool ret = Comp(p1, p2);
	if (ret)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	//解决办法
	//1.运算符重载
	//2.利用具体化的Person的版本实现Comp
}





int main() {
	test02();
}

