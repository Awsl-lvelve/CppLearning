#pragma once
#include<iostream>
#include<string>
using namespace std;

//如果除非特殊需要，写全局函数类内实现可能会更好


///printPerson2类外实现
template<class T1, class T2>
class Person;
//需要提前声明，告知编译器知道全局函数的存在
template<class T1, class T2>
void PrintPerson2(Person<T1, T2>& p);
///printPerson2类外实现



template<class T1,class T2>
class Person {
	//全局函数，类内实现
	//就是类内定义并声明一个函数
	friend void PrintPerson(Person<T1, T2>p) {
		p.ShowPerson();
	}

	friend void PrintPerson2<>(Person<T1, T2>& P);//添加空模板参数列表<>表明，PrintPerson2是函数模板
	//如果全局函数类外实现，需要编译器提前知道；
public:
	Person(T1 name, T2 age);
	
	void ShowPerson();

private:
	T1 m_Name;
	T2 m_Age;
};


template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson() {
	std::cout << this->m_Name << " ";
	std::cout << this->m_Age << std::endl;
};

//全局函数类外实现
//会出现，无法解析的外部命令问题
template<class T1, class T2>
void PrintPerson2(Person<T1, T2>&p) {
	p.ShowPerson();
}


