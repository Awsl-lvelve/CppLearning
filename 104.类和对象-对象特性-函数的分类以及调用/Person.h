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

//�޲ι��캯��-��ͨ����
Person::Person()
{
	std::cout << "Ĭ�Ϲ��캯������" << std::endl;
}

//�вι���-��ͨ����
Person::Person(std::string name) {
	std::cout << "�вι���" << std::endl;
	this->_name = name;
}

//��������
Person::Person(const Person& p) {
	std::cout << "��������" << std::endl;
	this->_name = p._name;
}

Person::~Person()
{
	std::cout << "������������" << std::endl;
}