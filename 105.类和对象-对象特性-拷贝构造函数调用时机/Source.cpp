//1.使用一个已经创建完毕的对象来初始化一个新对象


#include<iostream>
using namespace std;

class Person
{
public:
	Person();
	Person(int age);
	Person(const Person& p);
	~Person();
private:
	int age;
};

//默认构造
Person::Person() {
	cout << "默认构造函数" << endl;
}

//有参构造
Person::Person(int age)
{
	this->age = age;
	cout << "有参构造函数" << endl;
}

//拷贝构造
Person::Person(const Person& p) {
	cout << "拷贝构造" << endl;
	this->age = p.age;
}

Person::~Person()
{
	cout << "析构函数" << endl;
}

void test01()
{
	Person p1(85);
	Person p2(p1);//这里会用拷贝构造//1.使用一个已经创建完毕的对象来初始化一个新对象

}

void doWork(Person p) {
	cout << "what" << endl;
}

void test02() {
	Person p;
	doWork(p);//2.值传递的方式给参数传递值
}

Person doWork2() {
	Person p1;

	cout << (int*)&p1 << endl;//按理说这里p1就被销毁了，因为p1是个局部变量

	return p1;
}

//3.值方式返回局部对象
void test03() {
	Person p = doWork2();

	cout << (int*)&p << endl;//课程中，地址是不一样的，
	//但是在我的电脑上，p1和p的地址是完全相同，这表明p和p1是相同的东西
	//可能编译器发生了变更，这里两个地址是同样的
	//此外，这里并没有使用拷贝构造函数，这里和课程里面的又不一样
}



int main() {
	//test01();
	//test02();
	test03();

}


