#include<iostream>
#include<string>
using namespace std;

//��ģ��ͺ���ģ�������
//��ģ��û���Զ������Ƶ���ֻ����ʽָ������
//��ģ���ڲ����б��п���Ĭ�ϲ���

//��ģ�������Ĭ�ϲ���
template<class NameType,class AgeType=int>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;

	}

	void showPerson()
	{
		cout << "������" << this->m_Name << " ���䣺 " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test() {
	//Person p("ultraman", 1998)//��ģ�û����
	Person<string ,int> p("ultraman", 1998);//ֻ���������޷��Զ������Ƶ�
	p.showPerson();
}

void test02() {
	Person<string, int> p("ultramanZero", 20000); p.showPerson();
}

int main() {
	test02();
}

