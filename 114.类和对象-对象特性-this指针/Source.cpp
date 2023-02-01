#include<iostream>
using namespace std;

//this指针的概念
//每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
//这一块代码是如何区分是哪一个对象调用自己的？？

//this指针是这个问题的答案，this指针指向被调用的成员函数所属的对象
//this指针是隐含在每一个非静态成员函数内的指针
//this指针不需要定义，直接使用即可

//this指针的用途
//当形参和成员变量同名时，用于区分
//在类的非静态成员函数中返回对象本身时，可以使用return *this

class Person
{
public:
	Person(int age)
	{
		//如果这样写，那么这样相当于没有对属性age进行赋值
		//age = age;

		this->age = age;//正确实例
	}

	Person& PersonAddPerson(const Person& p) {
		//要以引用的方式返回，不然不会变动本身
		//如果是以值的方式返回：返回值类型为Person，而不是Person&，那么每次返回相当于调用拷贝构造函数生成一个新的对象
		this->age += p.age;
		return *this;//返回p2本体
	}

	~Person()
	{
	}

public :
	int age;

};

void test() {
	Person p1(18);
	Person p2(10);

	p2.PersonAddPerson(p1);
	p2.PersonAddPerson(p1).PersonAddPerson(p1);


	cout << p2.age << endl;
}

int main() {
	
	test();
}