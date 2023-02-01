#pragma once
#include<iostream>
using namespace std;

//Target
//���Զ������������ͺ��Զ����������ͽ��д洢
//���Խ��������ݴ洢������
//���캯���п��Դ�����������
//�ṩ��Ӧ�Ŀ������캯���Լ�operator=��Ӧǳ����������
//�ṩβ�巨��βɾ���������е����ݽ���ɾ��
//����ͨ���±��еķ�ʽ���������е�Ԫ��
//���Ի�ȡ�����е�ǰԪ�صĸ�������������

template<class T>
class MyArray {
	template<class T>
	friend ostream& operator<<(ostream& out, MyArray<T>arr) {
		for (int i = 0; i < arr.m_ElemNum(); i++)
		{
			out << *(arr.m_Array[i]) << " ";
		}
		out << endl;
	}

public:
	//interfaces
	MyArray(int capacity);//���캯��
	~MyArray();//��������
	MyArray(const MyArray& arr);//�������캯������ֹǳ����
	MyArray<T>& operator=(const MyArray& arr);//��ֵ��������أ���ֹǳ����

	//T AccesssElem(int index);//ͨ���±����Ԫ��
	T& operator[](int index);//ͨ���±����Ԫ��

	void PushBack(const T& elem);//βɾ��
	void PopBack();//βɾ��
	void PrintArray();

	//get-set����
	int GetCapacity() {
		return this->m_Capacity;
	}
	int GetElemNum() {
		return this->m_ElemNum;
	}
	T* GetArray() {
		return this->m_Array;
	}
	void SetCapacity(const int& capacity) {
		this->m_Capacity = capacity;
	}
	void SetElemNum(const int& elemNum) {
		this->m_ElemNum = elemNum;
	}
	void SetArray(T* array) {
		this->m_Array = array;
	}
private:
	T *m_Array;//Ԫ�ش洢
	int m_Capacity;//����
	int m_ElemNum;//��ǰԪ������
};


