#pragma once
#include<iostream>
using namespace std;

//Target
//可以对内置数据类型和自定义数据类型进行存储
//可以将数组内容存储到堆区
//构造函数中可以传入数组容量
//提供对应的拷贝构造函数以及operator=适应浅拷贝的问题
//提供尾插法和尾删法对数组中的数据进行删除
//可以通过下标中的方式访问数组中的元素
//可以获取数组中当前元素的个数和数组容量

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
	MyArray(int capacity);//构造函数
	~MyArray();//析构函数
	MyArray(const MyArray& arr);//拷贝构造函数，防止浅拷贝
	MyArray<T>& operator=(const MyArray& arr);//赋值运算符重载，防止浅拷贝

	//T AccesssElem(int index);//通过下标访问元素
	T& operator[](int index);//通过下标访问元素

	void PushBack(const T& elem);//尾删法
	void PopBack();//尾删法
	void PrintArray();

	//get-set方法
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
	T *m_Array;//元素存储
	int m_Capacity;//容量
	int m_ElemNum;//当前元素数量
};


