#include<iostream>
#include<string>

using namespace std;

//ȫ�ֱ���
int g_a = 10;

//ȫ�ֳ���
const int g_c_a = 100;

//��ջ��
int* func() {
	int a = 10;
	return &a;
}
//�ڶ���
int* func1() {
	int *p=new int(10);//ָ�뱾����һ���ֲ�������������ָ��������ڶ���
	return p;
}



int main() {
	////��ͨ�ֲ�����
	//int a = 10;
	//cout <<(int) & a << endl;
	//cout <<(int) & g_a << endl;
	////��̬�ֲ�
	//static int s_a = 100;
	//cout << (int)&s_a << endl;
	////�ֲ�����
	//const int c_a = 10;
	//cout << (int)&c_a << endl;
	//cout << (int)&g_c_a << endl;

	//int* p = func();//΢��������ƺ��ᱣ�����صľֲ������ĵ�ַ�����ǲ�������ô��
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;
	
	int* p = func1();


	cout << *p << endl;
	cout << *p << endl;
}