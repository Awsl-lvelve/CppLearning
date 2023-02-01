#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

template<class NameType,class AgeType>
class Person {
	friend ostream& operator<<(ostream& out, Person& person) {
		out << "ÐÕÃû£º" << person.GetName() << "\t" 
			<< "ÄêÁä£º" << person.GetAge()<<"\t";
		return out;
	};

public:
	Person();
	Person(NameType name, AgeType age);

	void SetName(const NameType& name);
	void SetAge(const AgeType &age);

	NameType GetName();

	AgeType GetAge();

private:
	NameType m_Name;
	AgeType m_Age;
};


template<class NameType, class AgeType>
Person<NameType,AgeType>::Person() {
	this->m_Name = "";
	this->m_Age = 0;
}

template<class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age) {
	this->m_Name = name;
	this->m_Age = age;
}

template<class NameType, class AgeType>
void Person<NameType, AgeType>::SetName(const NameType& name) {
	this->m_Name = name;
}

template<class NameType, class AgeType>
void Person<NameType, AgeType>::SetAge(const AgeType& age)
{
	this->m_Age = age;
}

template<class NameType, class AgeType>
NameType Person<NameType, AgeType>::GetName() {
	return this->m_Name;
}

template<class NameType, class AgeType>
AgeType Person<NameType, AgeType>::GetAge() {
	return this->m_Age;
}