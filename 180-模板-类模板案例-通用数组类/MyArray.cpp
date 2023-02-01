#include"MyArray.h"

template<class T>
MyArray<T>::MyArray(int capacity) {
	//cout << "�вι���" << endl;
	this->m_Capacity = capacity;
	this->m_ElemNum = 0;
	this->m_Array = new T(this->m_Capacity);
}

template<class T>
MyArray<T>::~MyArray()
{
	if (this->m_Array!=NULL)
	{
		delete[] this->m_Array;
		this->m_Array = NULL;
		//cout << "������������" << endl;
	}
	
}

template<class T>
MyArray<T>::MyArray(const MyArray& arr) {
	//cout << "��������" << endl;
	this->m_Capacity = arr.m_Capacity;
	this->m_ElemNum = arr.m_ElemNum;
	this->m_Array = new T[arr.m_Capacity];

	for (int i = 0; i < arr.m_ElemNum; i++)
	{
		this->m_Array[i] = arr.m_Array[i];
	}
};

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& arr) {
	
	//cout << "��ֵ�����" << endl;
	if (this->m_Array!=NULL)//��������
	{
		delete[] this->m_Array;
		this->m_Array = NULL;

		this->m_Capacity = 0;
		this->m_ElemNum = 0;
	}

	//���
	this->m_Capacity = arr.m_Capacity;
	this->m_ElemNum = arr.m_ElemNum;
	this->m_Array = new T[arr.m_Capacity];

	for (int i = 0; i < arr.m_ElemNum; i++)
	{
		this->m_Array[i] = arr.m_Array[i];
	}
	return *this;
}

template<class T>
T& MyArray<T>::operator[](int index)
{
	return this->m_Array[index];
}

template<class T>
void MyArray<T>::PushBack(const T& elem)
{
	if (this->m_Capacity==this->m_ElemNum)
	{
		cout << "��������������չ����" << endl;

		//�����¿ռ��С
		int newCapacity = this->m_Capacity + 50;
		//�����¿ռ�
		T* newSpace = new T[newCapacity];
		//����Ԫ��
		for (int i = 0; i < this->m_ElemNum; i++)
		{
			newSpace[i] = this->m_Array[i];
		}
		//����
		this->m_Array = newSpace;//����֮����¿ռ�
		this->m_Capacity = newCapacity;//��������
		this->m_ElemNum = this->m_ElemNum;//����Ŀǰ������
	}

	//���Ԫ��
	this->m_Array[this->m_ElemNum] = elem;//��ĩβ��������
	this->m_ElemNum++;//����Ԫ������

}

template<class T>
void MyArray<T>::PopBack()
{
	if (this->m_ElemNum==0)
	{
		cout << "������" << endl;
		return;
	}
	//���û����ʲ������һ��Ԫ�ؼ���
	this->m_ElemNum--;//�߼�ɾ��
}

template<class T>
void MyArray<T>::PrintArray()
{
	for (int i = 0; i < this->GetElemNum(); i++)
	{
		cout << this->m_Array[i] << " ";
	}
	cout << endl;

	//cout << *this;
}
