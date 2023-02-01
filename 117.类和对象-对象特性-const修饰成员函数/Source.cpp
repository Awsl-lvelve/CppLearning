#include<iostream>
using namespace std;

//成员函数后添加const 我们称之为常函数
//常函数内不可以修改成员属性
//成员属性添加关键字mutable时，在常函数中依然可以修改

//常对象
//声明对象前加const称为该对象为常对象
//常对象只能使用常函数
//类比static？

class Person
{
public:
	Person()=default;


	//this指针的本质：是指针常量，指针的指向不可更改，但是指向的对象的内容是可以更改的
	void ShowPerson()const
		//常函数的this指针: const Person* const this.
		//普通函数的this指针Person* const this
	{
		//this->_age = 100;//非mutable的成员在const函数内不可更嘎
		cout << this->_age << endl;
		this->_id = 1111;
		cout << this->_id << endl;
	}

	//普通成员函数
	void ShowId() {
		cout << this->_id << endl;
	}

private:
	 int _age;
	 mutable int _id;
};

void Test1() {
	Person p;
	p.ShowPerson();
}

void Test2() {
	const Person p;//常对象
	p.ShowPerson();//可以调用
	//p.ShowId();//常对象只能调用常函数，因为普通成员函数可以修改属性
}

int main() {
	Test1();
}
