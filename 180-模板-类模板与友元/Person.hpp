#pragma once
#include<iostream>
#include<string>
using namespace std;

//�������������Ҫ��дȫ�ֺ�������ʵ�ֿ��ܻ����


///printPerson2����ʵ��
template<class T1, class T2>
class Person;
//��Ҫ��ǰ��������֪������֪��ȫ�ֺ����Ĵ���
template<class T1, class T2>
void PrintPerson2(Person<T1, T2>& p);
///printPerson2����ʵ��



template<class T1,class T2>
class Person {
	//ȫ�ֺ���������ʵ��
	//�������ڶ��岢����һ������
	friend void PrintPerson(Person<T1, T2>p) {
		p.ShowPerson();
	}

	friend void PrintPerson2<>(Person<T1, T2>& P);//��ӿ�ģ������б�<>������PrintPerson2�Ǻ���ģ��
	//���ȫ�ֺ�������ʵ�֣���Ҫ��������ǰ֪����
public:
	Person(T1 name, T2 age);
	
	void ShowPerson();

private:
	T1 m_Name;
	T2 m_Age;
};


template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson() {
	std::cout << this->m_Name << " ";
	std::cout << this->m_Age << std::endl;
};

//ȫ�ֺ�������ʵ��
//����֣��޷��������ⲿ��������
template<class T1, class T2>
void PrintPerson2(Person<T1, T2>&p) {
	p.ShowPerson();
}


