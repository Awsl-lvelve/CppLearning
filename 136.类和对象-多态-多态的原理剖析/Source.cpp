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
	virtual void Speak() {
		cout << "Animal is speaking!" << endl;
	}

};

class Cat :public Animal {
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

void test1() {
	//这个test 要求去掉animal类的virtual关键字
	//Animal类
	cout << sizeof(Animal) << endl;//结果是1 空对象的占用空间是1 
	//现在添加上virtual关键字 32bit系统下是4Byte 64bit下是8byte
	//其本质是一个指针！！！
	//vfptr virtual function pointer 虚函数指针 or 虚函数表指针
	//指针指向虚函数表
	//vftable virtual function table
	//里面存放的就是虚函数
	//如图
	//-------------------------------
	//|												|
	//|				&Animal::Speak()		|
	//|												|
	//-------------------------------|

	//Cat
	//Cat继承的，没有重写的话,也是继承一个vfptr
	// 指向一个vftable，vftable内的内容为
	//-------------------------------|
	//|												|
	//|				&Animal::Speak()		|
	//|												|
	//-------------------------------|
	//
	//当子类重写了父类的虚函数
	//那么子类的虚函数表内部会替换成，子类的虚函数地址
	//-------------------------------|
	//|												|
	//|				&Cat::Speak()			|
	//|												|
	//-------------------------------|

	//当父类的指针或者引用指向子类的对象时，发生多态




}

int main() {
	test1();
}

