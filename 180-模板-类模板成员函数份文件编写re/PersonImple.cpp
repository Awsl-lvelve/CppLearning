#include "Person.cpp"

template<class T1, class T2 >
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
};

template<class T1, class T2>
void Person<T1, T2>::ShowPerson() {
	std::cout << this->m_Name << " ";
	std::cout << this->m_Age << std::endl;
}