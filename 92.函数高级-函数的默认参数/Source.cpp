#include<iostream>
using namespace std;


//������Ĭ�ϲ���
int func(int a, int b, int c = 100) {
	return a + b + c;
}


//��ĳ��������ʼ��Ĭ�ϲ����ˣ������Ĳ���Ҳ������Ĭ�ϲ���������ᱨ��
//int func1(int a, int b = 10, int c) {}

//���һ��������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ����
//���ʵ������Ĭ�ϲ�������ô���������Ͳ�����Ĭ����
int func2(int a = 20, int b = 100);

int func2(int a, int b) {
	return a * b;
}

int main()
{
	cout << func(1, 2) << endl;

	cout << func2() << endl;
}