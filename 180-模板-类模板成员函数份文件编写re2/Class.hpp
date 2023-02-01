#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
	NameType m_Name;
	AgeType m_Age;

	Person(NameType name, AgeType age);
	
	void ShowPerson();
};

template<class NameType,class AgeType>
inline Person<NameType, AgeType>::Person(NameType name,AgeType age) {
	this->m_Name = name;
	this->m_Age = age;
}

template<class NameType, class AgeType>
inline void Person<NameType, AgeType>::ShowPerson() {
	std::cout << this->m_Name << " ";
	std::cout << this->m_Age << std::endl;
}