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

int main() {
	test();
}

