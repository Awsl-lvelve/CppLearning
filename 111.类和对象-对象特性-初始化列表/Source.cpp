#include<iostream>
using namespace std;

class Person
{
public:
	//Person(string name, int age)
	//{
	//	this->_name = name;
	//	this->_age = new int(age);
	//}

	//������캯��
	Person(const Person& person) {
		this->_name = person._name;
		this->_age = new int(*person._age);
		cout << "������캯������" << endl;
	}

	//�б��ʼ��
	Person(string name, int age) :_name(name), _age(new int(age)) { cout << "���캯������" << endl; };

	~Person()
	{
		if (this->_age!=NULL)
		{
			delete _age;
			this->_age = NULL;//�ÿշ�ֹҰָ�����
		}
		cout << "��������" << endl;
	}

	string  _name;
	int *_age;

};

int main() {
	Person p("what", 19);
	Person p1(p);
}
