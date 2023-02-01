#include<iostream>
#include<string>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& out, const Person& p);
public:
	Person() {
		this->_name = new string("DefaultName");
		this->_age = -1;
	}//默认构造

	Person(int age, string name) {
		this->_name = new string(name);
		this->_age = age;

		//cout << "有参构造函数调用" << endl;
	};//有参构造

	Person(const Person& person) {
		this->_name = person._name;
		this->_age = person._age;
	}

	~Person() {
		if (this->_name!=NULL)
		{
			delete this->_name;
			this->_name = NULL;
		}
		//cout << "析构函数调用" << endl;
	};//析构

	//Person(const Person& person) {
	//	this->_age =person._age;
	//	this->_name = new string(*person._name);//重新开辟空间，避免析构时内存重复释放

	//	//测试是否调用拷贝构造函数
	//	//cout << "拷贝构造函数调用" << endl;

	//}//拷贝构造，深
	
	Person& operator+(const Person& p) {
		this->_age += p._age;
		return *this;
	}//+号运算符重载

	Person& operator-(const Person& p) {
		this->_age -= p._age;
		return *this;
	}//减号运算符重载

	Person& operator++() {
		++this->_age;
		return *this;
	}//前置递增

	Person operator++(int) {

		//后置递增返回的是值！不能返回局部变量的引用
		//Person temp = * this;
		//这样是错误的，你没有为temp的name开辟空间，会导致错误

		Person temp(this->_age, *this->_name);

		++this->_age;
		return temp;
	}//后置递增

	//这里存在一个问题，为了解决深浅拷贝问题而产生的深拷贝的构造函数
	//和普通的赋值符号
	//也可能仅仅利用编译器提供的默认的拷贝构造函数与重定义的赋值运算符
	//避免深浅拷贝的问题
	Person& operator=(Person& p) {
		//先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (this->_name!=NULL)
		{
			delete this->_name;
			this->_name = NULL;
		}

		this->_name = new string(*p._name);

		this->_age =p._age;

		return *this;
	}

	//get方法
	int GetAge()const {
		return this->_age;
	}

	string GetName()const {
		return *this->_name;
	}

	//set方法
	void SetAge(int age) {
		this->_age = age;
	}

	void SetName(string name) {
		this->_name = new string(name);
	}
private:
	int _age;
	string* _name;
};

//左移运算符重载
ostream& operator<<(ostream&out,const Person& p) {
	out << "年龄：" << p._age << " " << "姓名：" << *p._name;
	return out;
}

//构造函数测试-默认
void test01() {
	Person p1;
	p1.SetAge(18);
	p1.SetName("Ultraman");

	//打印
	cout << p1 << endl;	
}

//构造函数测试-有参
void test02() {
	Person p1(18,"Nexus");
	cout << p1 << endl;
}

//拷贝构造测试-拷贝
void test03() {
	Person p1(18, "Nexus");
	Person p2(p1);
}

//前置递增运算符测试
void test04() {
	Person p1(18, "Nexus");
	cout << p1 << endl;
	++p1;
	cout << p1 << endl;
	cout << ++(++p1) << endl;
}

//后置递增运算符测试
void test05() {
	Person p1(18, "Nexus");
	cout << p1 << endl;
	cout << p1++ << endl;
	cout << p1 << endl;
	cout << (p1++)++ << endl;
}

//int的递增
void testInt() {
	int a = 1;
	cout << ++a << endl;
	int b = 2;
	cout << b++ << endl;
	cout << b << endl;
}

//赋值运算符重载测试
void test06() {
	Person p1;
	cout << p1<<endl;

	Person p2=p1;
	//Person p2(p1);

	cout << p2 << endl;
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();

	//testInt();
	test06();

}
