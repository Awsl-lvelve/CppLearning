#include<iostream>
#include<string>

using namespace std;

class Animal {
public:
	virtual void Speak() = 0;
	//ֻҪ��һ�����麯�����������ǳ�����
	//�������޷�ʵ��������
	//���������д�����ി�麯��
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
	//Animal ani;//�������޷�ʵ��������
	//new Animal;//�������޷�ʵ��������
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