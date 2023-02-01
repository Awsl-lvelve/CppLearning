#include<iostream>
using namespace std;

//多态是C++面向对象的三大特性之一
//多态分类
//1.静态多态：函数重载和运算符重载
//2.动态多态：派生类和虚函数运行时多态

//静态和动态多态的区别
//静态多态的函数地址早绑定，编译阶段确定函数的地址
//动态多态的函数地址晚绑定，运行阶段确定函数的地址

class Animal {
public:
	//添加virtual关键字，使得动态多态实现，
	//子类需要重写父类的虚函数
	virtual void Speak()
	{
		cout << "animal is speaking!" << endl;
	}

};


class Cat:public Animal {
public:
	void Speak() {
		cout << "Cat is speaking!" << endl;
	}
};

class Dog :public Animal {
public:
	void Speak() {
		cout << "Dog is speaking!" << endl;
	}
};


//执行说话的函数
//地址早绑定，在编译阶段确定地址
//如果想执行猫说话，就需要晚绑定
//实现方式是 在animal的speak函数前加virtual
void DoSpeak(Animal& animal) {
	animal.Speak();
}

void test() {
	Cat cat;
	DoSpeak(cat);

	Dog dog;
	DoSpeak(dog);

	Animal animal;
	DoSpeak(animal);
}

int main() {
	test();
}

