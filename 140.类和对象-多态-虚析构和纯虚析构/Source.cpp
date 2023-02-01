//��̬ʹ��ʱ��������������Կ��ٵ�����
//��ô����ָ�����ͷ�ʱ���޷������������������
//�����ʽ�������������������Ϊ���������ߴ�������

//�������ʹ��������Ĺ���
//~�����Խ������ָ���ͷ��������
//~����Ҫ�о���ĺ���ʵ��

//�������ʹ�������������
//������������ô�������ڳ����࣬�޷�ʵ��������
#include<iostream>
using namespace std;


class Animal
{
public:
	Animal() {
		cout << "Animal �Ĺ��캯��" << endl;
	}
	//����������
	/*virtual ~Animal()
	{
		cout << "Animal ��������������" << endl; 
	}*/

	//����������Ǵ���������
	//��Ҫ�����ڲ�����������ʵ��
	virtual ~Animal() = 0;

	virtual void Speak() = 0;
};

Animal:: ~Animal()
{
	cout << "Animal ��������������" << endl;
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
		cout << "Cat �Ĺ��캯������" << endl;
		this->m_catName = new string(name);
	}


	~Cat() {
		if (this->m_catName!=NULL)
		{
			delete this->m_catName;
			this->m_catName = NULL;

			cout << "Cat ��������������" << endl;
			//����ָ��������ʱ�� ������������е��������������������������������������
			//��������ж������ԣ������ڴ�й¶
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



