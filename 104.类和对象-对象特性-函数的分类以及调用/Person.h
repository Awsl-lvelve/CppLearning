#pragma once
#include<string>
#include<iostream>

class Person
{
public:
	Person();
	Person(std::string name);
	Person(const Person& p);
	~Person();

private:
	std::string _name;

};

//无参构造函数-普通构造
Person::Person()
{
	std::cout << "默认构造函数调用" << std::endl;
}

//有参构造-普通构造
Person::Person(std::string name) {
	std::cout << "有参构造" << std::endl;
	this->_name = name;
}

//拷贝构造
Person::Person(const Person& p) {
	std::cout << "拷贝构造" << std::endl;
	this->_name = p._name;
}

Person::~Person()
{
	std::cout << "析构函数调用" << std::endl;
}