#include<iostream>
#include<string>
using namespace std;

//ѧϰĿ�꣺
//1.ָ����������	--ֱ����ʽָ���������������			��ʵ�ʿ��������У���һ������õģ�
//2.����ģ�廯		--�������еĲ�����Ϊģ����д���
//3.������ģ�廯	--����������ģ�廯���д���
//��2.3�Ǻ���ģ�����ģ�����ϣ�̫�����ӣ�һ�㲻��

template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name,AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << "������" << this->m_Name << " ";
		cout << "���䣺" << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void PrintPerson(Person<string, int>& p) {
	p.showPerson();
}
//1.ָ����������	--ֱ����ʾ�������������
void test01() {
	Person<string, int> p1("�����", 1984);
	PrintPerson(p1);
}
//2.����ģ�廯		--�������еĲ�����Ϊģ����д���
template<class T1,class T2>
void PrintPerson2(Person<T1,T2>&p) {
	p.showPerson();

	cout << "T1�����ͣ�" << typeid(T1).name() << endl;
	cout << "T2�����ͣ�" << typeid(T2).name() << endl;
}

void test02() {
	Person<string, int> p("UltramanNexus", 1997);
	PrintPerson2(p);
}

//3.������ģ�廯	--����������ģ�廯���д���
template<class T>
void PrintPerson3(T person) {
	person.showPerson();
	cout << "T���������ͣ�" << typeid(T).name () << endl;
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