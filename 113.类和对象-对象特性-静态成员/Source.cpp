#include<iostream>
using namespace std;

//��̬��Ա����
//���ж�����ͬһ������
//�ڱ���׶η����ڴ�
//���������������ʼ��

//��̬��Ա����������ĳ�������ϣ����ж�����һ������
//���ַ��ʷ�ʽ
//ͨ���������
//ͨ���������з���

//��̬��Ա����Ҳ���з���Ȩ�޵�


//��̬��Ա����
//1.���ж�����ͬһ������
//2.��̬��Ա����ֻ�ܷ��ʾ�̬�ĳ�Ա����



class Person
{
public:

	static void func() {
		cout << "static void func����" << endl;
		m_A = 100;
		//nonstaticA = 100;//��̬��Ա�������ܷ��ʷǾ�̬��Ա����
		//��Ϊ���Ǿ�̬��Ա�������ھ���Ķ������ģ���̬��Ա��������ʱ�޷����ַǾ�̬��Ա�����ھ�����һ��
	}


	static int m_A;
	int nonstaticA;
private:

	static void func2() {
		cout << "static void func2����" << endl;
	}


	static int m_B;
};
//�����ʼ��
int Person::m_A=100;
int Person::m_B = 300;

void test() {
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p2.m_A << endl;

	cout << p.m_A << endl;

	//ͨ���������ʣ�
	cout<<Person::m_A << endl;


	//private��static��Ա���������ǲ��ɷ��ʵ�
	//cout << Person::m_B << endl;
	//Person::func2();
}

void test2() {
	Person p;
	p.func();

	Person::func();
}




int main() {
	//test();
	test2();
}