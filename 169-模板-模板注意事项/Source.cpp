#include<iostream>
using namespace std;

//����ģ��
//1.�Զ������Ƶ������뵼��һ�µ���������
//2.ģ�����Ҫȷ��T���������Ͳ���ʹ��

template<class T>
void MySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void Func() { cout << "Func����" << endl; }

void test01() {
	int a = 10;
	int b = 20;

	MySwap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	char c = 11;
	//MySwap(a, c);
	//cout << "a=" << a << endl;
	//cout << "c=" << b << endl;
	//�Ƶ�����һ�µ�T���͵Ĳ���
}

void test02() {
	//Func();//��ȷ���������ͣ��ᱨ��
	Func<int>();//��ʽָ��T���ͣ����Ե��ô���
}

int main() {
	test01();
	test02();
}