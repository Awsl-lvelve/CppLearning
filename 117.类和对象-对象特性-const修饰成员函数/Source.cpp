#include<iostream>
using namespace std;

//��Ա���������const ���ǳ�֮Ϊ������
//�������ڲ������޸ĳ�Ա����
//��Ա������ӹؼ���mutableʱ���ڳ���������Ȼ�����޸�

//������
//��������ǰ��const��Ϊ�ö���Ϊ������
//������ֻ��ʹ�ó�����
//���static��

class Person
{
public:
	Person()=default;


	//thisָ��ı��ʣ���ָ�볣����ָ���ָ�򲻿ɸ��ģ�����ָ��Ķ���������ǿ��Ը��ĵ�
	void ShowPerson()const
		//��������thisָ��: const Person* const this.
		//��ͨ������thisָ��Person* const this
	{
		//this->_age = 100;//��mutable�ĳ�Ա��const�����ڲ��ɸ���
		cout << this->_age << endl;
		this->_id = 1111;
		cout << this->_id << endl;
	}

	//��ͨ��Ա����
	void ShowId() {
		cout << this->_id << endl;
	}

private:
	 int _age;
	 mutable int _id;
};

void Test1() {
	Person p;
	p.ShowPerson();
}

void Test2() {
	const Person p;//������
	p.ShowPerson();//���Ե���
	//p.ShowId();//������ֻ�ܵ��ó���������Ϊ��ͨ��Ա���������޸�����
}

int main() {
	Test1();
}
