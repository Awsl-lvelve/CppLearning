#include<iostream>
#include<string>

using namespace std;

class Animal {
public:
	virtual void Speak() = 0;
	//只要有一个纯虚函数，这个类就是抽象类
	//抽象类无法实例化对象
	//子类必须重写抽象类纯虚函数
};

class Dog:public Animal{
public:
	virtual void Speak()  {
		cout << "Dog is speaking!" << endl;
	}
};

class Cat:public Animal {
public:
	virtual void Speak() {
		cout << "Cat is speaking!" << endl;
	}
};

void test() {
	//Animal ani;//抽象类无法实例化对象
	//new Animal;//抽象类无法实例化对象
	Cat cat;
	cat.Speak();

	Dog dog;
	dog.Speak();

	Animal* ani = new Cat;
	ani->Speak();

	Animal* ani1 = new Dog;
	ani1->Speak();
}

int main() {
	test();
}