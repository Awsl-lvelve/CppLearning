#include<iostream>
#include<string>
using namespace std;

//类模板中成员函数类外实现
template<class NameType,class AgeType>
class Person {
public:
	NameType m_Name;
	AgeType m_Age;
	
	//类内声明
	Person(NameType name, AgeType age); 

	void showPerson();


};

//类外实现
template<class NameType,class AgeType>
Person<NameType,AgeType>::Person(NameType name, AgeType age){
	this->m_Name = name;
	this->m_Age = age;
}

template<class NameType, class AgeType>
void Person<NameType, AgeType>::showPerson() {
	cout << "姓名：" << this->m_Name << " ";
	cout << "年龄：" << this->m_Age << endl;
}

void test() {
	Person<string, int>p("Ultraman", 29999);
	p.showPerson();
}

int main() {
	test();
}