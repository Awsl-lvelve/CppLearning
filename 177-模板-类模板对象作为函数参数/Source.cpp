#include<iostream>
#include<string>
using namespace std;

//学习目标：
//1.指定传入类型	--直接显式指定对象的数据类型			在实际开发过程中，这一条是最常用的！
//2.参数模板化		--将对象中的参数变为模板进行传递
//3.整个类模板化	--将对象类型模板化进行传递
//第2.3是函数模板和类模板的配合，太过复杂，一般不用

template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name,AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << "姓名：" << this->m_Name << " ";
		cout << "年龄：" << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void PrintPerson(Person<string, int>& p) {
	p.showPerson();
}
//1.指定传入类型	--直接显示对象的数据类型
void test01() {
	Person<string, int> p1("孙悟空", 1984);
	PrintPerson(p1);
}
//2.参数模板化		--将对象中的参数变为模板进行传递
template<class T1,class T2>
void PrintPerson2(Person<T1,T2>&p) {
	p.showPerson();

	cout << "T1的类型：" << typeid(T1).name() << endl;
	cout << "T2的类型：" << typeid(T2).name() << endl;
}

void test02() {
	Person<string, int> p("UltramanNexus", 1997);
	PrintPerson2(p);
}

//3.整个类模板化	--将对象类型模板化进行传递
template<class T>
void PrintPerson3(T person) {
	person.showPerson();
	cout << "T的数据类型：" << typeid(T).name () << endl;
}

void test03() {
	Person<string, int> p("UltramanSeven", 1997);
	PrintPerson3(p);
}


int main() {
	//test01();
	//test02();
	test03();
}