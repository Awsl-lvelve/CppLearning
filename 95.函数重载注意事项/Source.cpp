#include<iostream>
using namespace std;

//������������Ĭ�ϲ���
//���ÿ�����Ϊ���ص�����

void func(int& a) {
	cout << "func(int&a)" << endl;
}

void func(const int& a) {
	cout << "func(const int&a)" << endl;
}

//Ĭ�ϲ���������Ϊ����������������ͻ
// ��һ������������⣬����ֶ����ԣ���������������⣬������ֶ�����
//void func(int a,int b=10) {
//	cout << "func(int a,int b=default)" << endl;
//}



int main()
{
	int a = 10;
	func(a);//���������

	const int b = 10;
	func(b);//���������
	func(20);//���������

}