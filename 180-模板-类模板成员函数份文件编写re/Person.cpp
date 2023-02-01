#pragma once
#include<iostream>
#include<string>
using namespace std;

//类模板的分文件编写产生的问题以及解决办法

//问题
//类模板中成员函数创建时机是在调用阶段，导致分文件编写时连接不到

//解决1：直接包含.cpp源文件
//解决2：将声明和实现写到同一个文件中，并更改后缀名为.hpp,hpp是约定的名称，并不强制


template<class T1,class T2>
class Person
{
public:
	T1 m_Name;
	T2 m_Age;

	void ShowPerson();

	Person(T1 name, T2 age);

};

