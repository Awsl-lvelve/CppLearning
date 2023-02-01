#pragma once
#include<iostream>
#include<string>

template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType name,AgeType age);

	void showPerson();

	NameType m_Name;
	AgeType m_Age;
};
;
