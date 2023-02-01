#include<iostream>
#include<string>
using namespace std;

//��ģ���г�Ա��������ʵ��
template<class NameType,class AgeType>
class Person {
public:
	NameType m_Name;
	AgeType m_Age;
	
	//��������
	Person(NameType name, AgeType age); 

	void showPerson();


};

//����ʵ��
template<class NameType,class AgeType>
Person<NameType,AgeType>::Person(NameType name, AgeType age){
	this->m_Name = name;
	this->m_Age = age;
}

template<class NameType, class AgeType>
void Person<NameType, AgeType>::showPerson() {
	cout << "������" << this->m_Name << " ";
	cout << "���䣺" << this->m_Age << endl;
}

void test() {
	Person<string, int>p("Ultraman", 29999);
	p.showPerson();
}

int main() {
	test();
}