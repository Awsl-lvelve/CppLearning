#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ģ��ķ��ļ���д�����������Լ�����취

//����
//��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���

//���1��ֱ�Ӱ���.cppԴ�ļ�
//���2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp,hpp��Լ�������ƣ�����ǿ��


template<class T1,class T2>
class Person
{
public:
	T1 m_Name;
	T2 m_Age;

	void ShowPerson();

	Person(T1 name, T2 age);

};

