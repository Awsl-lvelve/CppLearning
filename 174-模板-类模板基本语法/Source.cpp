#include<iostream>
#include<string>
using namespace std;


template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_name = name;
		this->m_age = age;
	}

	void showPerson()
	{
		cout << "������" <<this->m_name<<" ";
		cout << "���䣺" << this->m_age << endl;
	}


	NameType m_name;
	AgeType m_age;

};


void test01() {
	Person<string, int> p("�����", 188);
	p.showPerson();

}





int main() {
	test01();
}