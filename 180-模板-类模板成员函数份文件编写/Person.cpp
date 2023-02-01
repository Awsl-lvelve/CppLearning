#include "Person1.hpp"

template<class NameType,class AgeType>
Person<NameType,AgeType>::Person(NameType name, AgeType age) {
	this->m_Name = name;
	this->m_Age = age;
}


template<class NameType,class AgeType>
void Person<NameType, AgeType>::showPerson() {
	std::cout << this->m_Name << std::endl;
	std::cout << this->m_Age << std::endl;
}