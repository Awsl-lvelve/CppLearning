#include<iostream>
using namespace std;

class Person
{
public:
	//Person(string name, int age)
	//{
	//	this->_name = name;
	//	this->_age = new int(age);
	//}

	//深拷贝构造函数
	Person(const Person& person) {
		this->_name = person._name;
		this->_age = new int(*person._age);
		cout << "深拷贝构造函数调用" << endl;
	}

	//列表初始化
	Person(string name, int age) :_name(name), _age(new int(age)) { cout << "构造函数调用" << endl; };

	~Person()
	{
		if (this->_age!=NULL)
		{
			delete _age;
			this->_age = NULL;//置空防止野指针出现
		}
		cout << "析构函数" << endl;
	}

	string  _name;
	int *_age;

};

int main() {
	Person p("what", 19);
	Person p1(p);
}
