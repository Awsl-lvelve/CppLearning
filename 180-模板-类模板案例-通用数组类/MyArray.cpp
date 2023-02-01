#include"MyArray.h"

template<class T>
MyArray<T>::MyArray(int capacity) {
	//cout << "有参构造" << endl;
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
		//cout << "析构函数调用" << endl;
	}
	
}

template<class T>
MyArray<T>::MyArray(const MyArray& arr) {
	//cout << "拷贝构造" << endl;
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
	
	//cout << "赋值运算符" << endl;
	if (this->m_Array!=NULL)//必须这样
	{
		delete[] this->m_Array;
		this->m_Array = NULL;

		this->m_Capacity = 0;
		this->m_ElemNum = 0;
	}

	//深拷贝
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
		cout << "容量已满，将扩展容量" << endl;

		//计算新空间大小
		int newCapacity = this->m_Capacity + 50;
		//开辟新空间
		T* newSpace = new T[newCapacity];
		//拷贝元素
		for (int i = 0; i < this->m_ElemNum; i++)
		{
			newSpace[i] = this->m_Array[i];
		}
		//更新
		this->m_Array = newSpace;//拷贝之后更新空间
		this->m_Capacity = newCapacity;//更新容量
		this->m_ElemNum = this->m_ElemNum;//人数目前还不变
	}

	//添加元素
	this->m_Array[this->m_ElemNum] = elem;//在末尾插入数据
	this->m_ElemNum++;//更新元素数量

}

template<class T>
void MyArray<T>::PopBack()
{
	if (this->m_ElemNum==0)
	{
		cout << "空数组" << endl;
		return;
	}
	//让用户访问不到最后一个元素即可
	this->m_ElemNum--;//逻辑删除
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
