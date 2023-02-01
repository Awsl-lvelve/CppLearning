//浅拷贝：编译器提供的简单赋值操作就一个等号而已
//深拷贝：在堆区重新申请一块空间，进行拷贝赋值操作
#include <iostream>
using namespace std;

class person
{
public:
	person();
	person(int age, int height);
	person(const person& p);
	~person();
public:
	int m_age;
	int* m_height;//用指针是想把身高开辟到堆区；
};

person::person()
{
	cout << "person的默认构造函数调用！" << endl;
}


//如果不设置如下的拷贝构造函数，仅仅使用浅拷贝操作（使用默认的拷贝构造函数），会导致重复释放内存的问题。
//解决办法是，重新在堆区申请内存，使得P1，p2的height存在不同地址当中，
//自己做一个拷贝构造函数
person::person(const person& p)
{
	cout << "person拷贝构造函数调用" << endl;
	//m_height=p.m_height//编译器是这么给的拷贝构造函数，s是浅拷贝这是导致问题的根源
	//解决办法如下
	//编译器提供的拷贝构造函数
	/*m_height = p.m_height;
	m_age = p.m_age;
	*/

	//深拷贝操作
	m_height = new int(*p.m_height);// 这里新建了一个空间，这个空间存了和P1.height相同的值(*p.m_height),但是有了新的地址。
	m_age = p.m_age;
}

person::person(int age, int height)
{
	m_height = new int(height);//返回一个int *，被m_height接收
	m_age = age;
	cout << "person的有参构造函数！" << endl;
}

person::~person()//析构代码，将堆开辟数据做释放操作
{
	if (this->m_height != NULL)
	{
		delete  m_height;//这里带来的问题是导致重复释放，会报错
		//解决办法:让P1 p2指向不同的内存，但是指的值是一样的
		m_height = NULL;//防止野指针出现，将其置空
	}
	cout << "person的析构函数调用！" << endl;
}

void test01()
{
	person p1(18, 1600);
	cout << "p1的年龄为" << p1.m_age <<" " << "身高为" << *p1.m_height << endl;
	cout << "p1的地址" << (int)&p1 << endl;

	person p2(p1);
	cout << "p2的地址" << (int)&p2 << endl;
	cout << "p2的年龄为" << p2.m_age << " " << "身高为" << *p2.m_height << endl;
}

int main()
{
	test01();
}