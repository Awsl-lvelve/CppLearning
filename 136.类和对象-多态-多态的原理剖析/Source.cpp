#include<iostream>
using namespace std;

//��̬��C++����������������֮һ
//��̬����
//1.��̬��̬���������غ����������
//2.��̬��̬����������麯������ʱ��̬

//��̬�Ͷ�̬��̬������
//��̬��̬�ĺ�����ַ��󶨣�����׶�ȷ�������ĵ�ַ
//��̬��̬�ĺ�����ַ��󶨣����н׶�ȷ�������ĵ�ַ

class Animal {
public:
	//���virtual�ؼ��֣�ʹ�ö�̬��̬ʵ�֣�
	//������Ҫ��д������麯��
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


//ִ��˵���ĺ���
//��ַ��󶨣��ڱ���׶�ȷ����ַ
//�����ִ��è˵��������Ҫ���
//ʵ�ַ�ʽ�� ��animal��speak����ǰ��virtual
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
	//���test Ҫ��ȥ��animal���virtual�ؼ���
	//Animal��
	cout << sizeof(Animal) << endl;//�����1 �ն����ռ�ÿռ���1 
	//���������virtual�ؼ��� 32bitϵͳ����4Byte 64bit����8byte
	//�䱾����һ��ָ�룡����
	//vfptr virtual function pointer �麯��ָ�� or �麯����ָ��
	//ָ��ָ���麯����
	//vftable virtual function table
	//�����ŵľ����麯��
	//��ͼ
	//-------------------------------
	//|												|
	//|				&Animal::Speak()		|
	//|												|
	//-------------------------------|

	//Cat
	//Cat�̳еģ�û����д�Ļ�,Ҳ�Ǽ̳�һ��vfptr
	// ָ��һ��vftable��vftable�ڵ�����Ϊ
	//-------------------------------|
	//|												|
	//|				&Animal::Speak()		|
	//|												|
	//-------------------------------|
	//
	//��������д�˸�����麯��
	//��ô������麯�����ڲ����滻�ɣ�������麯����ַ
	//-------------------------------|
	//|												|
	//|				&Cat::Speak()			|
	//|												|
	//-------------------------------|

	//�������ָ���������ָ������Ķ���ʱ��������̬




}

int main() {
	test1();
}

