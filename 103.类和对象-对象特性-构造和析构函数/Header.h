#pragma once
#include<string>

class Student
{
public:
	Student(std::string name,int age);
	~Student();

private:
	std::string _name;
	int _age;
};

Student::Student(std::string name, int age) {
	this->_name = name;
	this->_age = age;
	std::cout << "���캯������" << std::endl;
}

Student::~Student() {
	std::cout << "������������" << std::endl;
}