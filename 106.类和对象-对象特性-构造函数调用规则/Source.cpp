#include<iostream>
using namespace std;

//构造函数调用规则
//用户定义了有参构造，那么将不再提供无参构造函数,但是会提供拷贝构造函数
//如果用户定义了拷贝构造，那么将不再提供其他的普通构造函数

class Person
{
public:
	Person();
	Person(const Person& p);
	~Person();
	Person& operator=(const Person& rhs);
	std::string _name;
};

Person::Person()
{
	cout << "无参构造函数" << endl;
}

Person::~Person()
{
	cout << "析构函数" << endl;
}

Person& Person::operator=(const Person& rhs)
{
	// TODO: insert return statement here
	this->_name = rhs._name;
}

Person::Person(const Person& p) {
	this->_name = p._name;
	cout << "拷贝构造函数" << endl;
}

void test() {
	Person p;
	p._name = "Hello";
	Person p2(p);

	ppkpk;
}

int main() {
	test();
}