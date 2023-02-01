#pragma once
#include<iostream>
#include<string>
using namespace std;


template<class T>
class MyArray {
	friend ostream& operator<<(ostream& out,MyArray& arr) {
		for (int i = 0; i < arr.GetElemNum(); i++)
		{
			cout << arr.GetArray()[i]<<'\t';
		}
		cout << endl;
		return out;
	};
public:
	MyArray(int capacity);
	MyArray(const MyArray& arr);
	~MyArray();

	void PushBack(T val);
	void PopBack();
	
	MyArray& operator=(MyArray& arr);
	T& operator[](int index);

	int GetCapacity();
	int GetElemNum();
	T* GetArray();

private:
	T* m_Array;
	int m_ElemNum;
	int m_Capacity;
};

template<class T>
MyArray<T>::~MyArray() {
	if (this->m_Array!=NULL)
	{
		delete[] this->m_Array;
		this->m_Array = NULL;
		this->m_ElemNum = 0;
		this->m_Capacity = 0;
	}
}

template<class T>
MyArray<T>::MyArray(int capacity) {
	this->m_ElemNum = 0;
	this->m_Capacity = capacity;

	this->m_Array = new T[this->m_Capacity];
}

template<class T>
int MyArray<T>::GetCapacity() {
	return this->m_Capacity;
}

template<class T>
int MyArray<T>::GetElemNum() {
	return this->m_ElemNum;
}

template<class T>
inline void MyArray<T>::PushBack(T val) {
	if (this->m_ElemNum == this->m_Capacity)
	{
		cout << "空间已满，将扩容" << endl;

		int newCapacity = this->m_Capacity + 50;
		T* newSpace = new T[newCapacity];

		for (int i = 0; i < this->m_ElemNum; i++)
		{
			newSpace[i] = this->m_Array[i];
		}
		
		this->m_Array = newSpace;
		this->m_Capacity = newCapacity;
	}
	this->m_Array[this->m_ElemNum] = val;
	this->m_ElemNum++;

}

template<class T>
inline void MyArray<T>::PopBack() {
	if (this->m_ElemNum == 0)
	{
		cout << "空数组" << endl;
		return;
	}
	//让用户访问不到最后一个元素即可
	this->m_ElemNum--;//逻辑删除
}

template<class T>
inline MyArray<T>::MyArray(const MyArray& arr)
{
	this->m_Capacity = arr.m_Capacity;
	this->m_ElemNum = arr.m_ElemNum;
	this->m_Array = new T[this->m_Capacity];
	
	for (int i = 0; i < this->m_ElemNum; i++)
	{
		this->m_Array[i] = arr.m_Array[i];
	}
}

template<class T>
inline T* MyArray<T>::GetArray() {
	return this->m_Array;
}

template<class T>
inline MyArray<T>& MyArray<T>::operator=(MyArray<T>& arr)
{
	if (this->m_Array!=NULL)
	{
		//清空
		delete[]  this->m_Array;
		this->m_Array = NULL;

		this->m_Capacity = 0;
		this->m_ElemNum = 0;
	}
	//深拷贝
	this->m_Capacity = arr.m_Capacity;
	this->m_ElemNum = arr.m_ElemNum;
	this->m_Array = new T[this->m_ElemNum];

	for (int i = 0; i < this->m_ElemNum; i++)
	{
		this->m_Array[i] = arr.m_Array[i];
	}

	return *this;
}

template<class T>
inline T& MyArray<T>::operator[](int index) {
	if (index<=this->m_ElemNum-1)//有效下标
	{
		return this->m_Array[index];
	}
	else
	{
		cout << "越界" << endl;
		return;
	}
}