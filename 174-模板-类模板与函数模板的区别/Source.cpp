#include<iostream>
#include<string>
using namespace std;

//类模板和函数模板的区别
//类模板没有自动类型推导！只有显式指定类型
//类模板在参数列表中可有默认参数

//类模板可以有默认参数
template<class NameType,class AgeType=int>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;

	}

	void showPerson()
	{
		cout << "姓名：" << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test() {
	//Person p("ultraman", 1998)//错的，没法用
	Person<string ,int> p("ultraman", 1998);//只能这样，无法自动类型推导
	p.showPerson();
}

void test02() {
	Person<string, int> p("ultramanZero", 20000); p.showPerson();
}

int main() {
	test02();
}

