//多态使用时，如果子类有属性开辟到堆区
//那么父类指针在释放时，无法调用子类的析构代码
//解决方式：将父类的析构函数改为虚析构或者纯虚析构

//虚析构和纯虚析构的共性
//~都可以解决父类指针释放子类对象
//~都需要有具体的函数实现

//虚析构和纯虚析构的区别
//纯虚析构，那么这类属于抽象类，无法实例化对象
#include<iostream>
using namespace std;


class Animal
{
public:
	Animal() {
		cout << "Animal 的构造函数" << endl;
	}
	//虚析构函数
	/*virtual ~Animal()
	{
		cout << "Animal 的析构函数调用" << endl; 
	}*/

	//现在这个就是纯虚析构了
	//需要在类内部声明，类外实现
	virtual ~Animal() = 0;

	virtual void Speak() = 0;
};

Animal:: ~Animal()
{
	cout << "Animal 的析构函数调用" << endl;
}


class Cat:public Animal
{
public:
	virtual void Speak() {
		cout << "Cat is speaking!" << endl;
		cout << "Cat's name is " << *this->m_catName << endl;
	}

	Cat() = default;

	Cat(string name) {
		cout << "Cat 的构造函数调用" << endl;
		this->m_catName = new string(name);
	}


	~Cat() {
		if (this->m_catName!=NULL)
		{
			delete this->m_catName;
			this->m_catName = NULL;

			cout << "Cat 的析构函数调用" << endl;
			//父类指针在析构时候 不会调用子类中的析构函数，不会调用子类中析构函数，导致
			//子类如果有堆区属性，出现内存泄露
		}
	}

	
	string* m_catName;
};

void test01() {
	Animal* animal = new Cat("Tom");
	animal->Speak();
	delete animal;
}

int main() {
	test01();
}



