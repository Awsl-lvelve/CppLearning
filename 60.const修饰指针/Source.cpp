#include<iostream>
using namespace std;

int main() {
	int a = 100;
	int b = 1000;
	const int* p = &a;
	//ָ��ָ���ֵ�������
	//*p = 1000;
	
	//ָ���ָ����Ը�
	cout << "ԭ��ָ��ָ��Ŀռ������" << endl;
	cout << *p << endl;
	cout << "����ָ��ָ��Ŀռ������" << endl;
	p = &b;
	cout<<*p;

	int c = 99;
	int d = 89;
	int* const p1 = &c;
	//ָ���ָ��׼��
	//p1 = &d;
	//����ָ���ֵ���Ը�
	*p1 = 999;

	int e = 133;
	int f = 22;
	const int* const p2 = &e;
	//ָ��ķ����ܸ�
	//p2 = &f;
	
	//ָ��ķ����Ӧ������Ҳ���ܸ�
	//*p2 = 111;
}