#include<iostream>
using namespace std;

//ģ�������
//ģ�岢�������ܵأ���Щ�ض����������ͣ���Ҫ���廯�ķ�ʽ����ʵ��
//�Զ������ͣ�����

//�Ա����������Ƿ����
template<class T>
bool Comp(T& a,T& b) {
	if (a==b)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void test01() {
	int a = 10;
	int b = 10;

	bool ret = Comp(a, b);
	if (ret)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

class Person {
public:
	std::string m_name;
	int m_age;

	Person(std::string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	bool operator==(Person& p) {
		if (this->m_age==p.m_age&&this->m_name==p.m_name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//���þ��廯��Person�İ汾ʵ��Comp
template<> bool Comp(Person& a, Person& b) {
	cout << "�����ģ����廯Comp�˻����ģ�" << endl;
	//��������������������������
	//�����������廯��Compע���ˣ��ͻ������������
	if (a.m_name == b.m_name && a.m_age == b.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void test02() {
	Person p1("Tom",18);
	Person p2("Tom", 199);
	bool ret = Comp(p1, p2);
	if (ret)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}

	//����취
	//1.���������
	//2.���þ��廯��Person�İ汾ʵ��Comp
}





int main() {
	test02();
}

