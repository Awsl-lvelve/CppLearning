//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���


#include<iostream>
using namespace std;

class Person
{
public:
	Person();
	Person(int age);
	Person(const Person& p);
	~Person();
private:
	int age;
};

//Ĭ�Ϲ���
Person::Person() {
	cout << "Ĭ�Ϲ��캯��" << endl;
}

//�вι���
Person::Person(int age)
{
	this->age = age;
	cout << "�вι��캯��" << endl;
}

//��������
Person::Person(const Person& p) {
	cout << "��������" << endl;
	this->age = p.age;
}

Person::~Person()
{
	cout << "��������" << endl;
}

void test01()
{
	Person p1(85);
	Person p2(p1);//������ÿ�������//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���

}

void doWork(Person p) {
	cout << "what" << endl;
}

void test02() {
	Person p;
	doWork(p);//2.ֵ���ݵķ�ʽ����������ֵ
}

Person doWork2() {
	Person p1;

	cout << (int*)&p1 << endl;//����˵����p1�ͱ������ˣ���Ϊp1�Ǹ��ֲ�����

	return p1;
}

//3.ֵ��ʽ���ؾֲ�����
void test03() {
	Person p = doWork2();

	cout << (int*)&p << endl;//�γ��У���ַ�ǲ�һ���ģ�
	//�������ҵĵ����ϣ�p1��p�ĵ�ַ����ȫ��ͬ�������p��p1����ͬ�Ķ���
	//���ܱ����������˱��������������ַ��ͬ����
	//���⣬���ﲢû��ʹ�ÿ������캯��������Ϳγ�������ֲ�һ��
}



int main() {
	//test01();
	//test02();
	test03();

}


