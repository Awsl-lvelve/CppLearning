#include<iostream>
using namespace std;

//thisָ��ĸ���
//ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����
//��һ������������������һ����������Լ��ģ���

//thisָ�����������Ĵ𰸣�thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
//thisָ����������ÿһ���Ǿ�̬��Ա�����ڵ�ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

//thisָ�����;
//���βκͳ�Ա����ͬ��ʱ����������
//����ķǾ�̬��Ա�����з��ض�����ʱ������ʹ��return *this

class Person
{
public:
	Person(int age)
	{
		//�������д����ô�����൱��û�ж�����age���и�ֵ
		//age = age;

		this->age = age;//��ȷʵ��
	}

	Person& PersonAddPerson(const Person& p) {
		//Ҫ�����õķ�ʽ���أ���Ȼ����䶯����
		//�������ֵ�ķ�ʽ���أ�����ֵ����ΪPerson��������Person&����ôÿ�η����൱�ڵ��ÿ������캯������һ���µĶ���
		this->age += p.age;
		return *this;//����p2����
	}

	~Person()
	{
	}

public :
	int age;

};

void test() {
	Person p1(18);
	Person p2(10);

	p2.PersonAddPerson(p1);
	p2.PersonAddPerson(p1).PersonAddPerson(p1);


	cout << p2.age << endl;
}

int main() {
	
	test();
}