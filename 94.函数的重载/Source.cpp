#include<iostream>
using namespace std;

//����
///ͬһ��������
//��������ͬ
//�������������͡��������߶��߶���ͬ

//�����ķ���ֵ�����������أ�����

void func(int a, int b, int c) {
	cout << a + b + c<<"i"<<endl;
}

void func(int a, int b, int c,int d) {
	cout << a + b + c + d <<"j"<< endl;
}

void func(double a, int b, int c) {
	cout << a + b + c <<"k"<< endl;;
}

int main() {
	func(1, 2, 3);
	func(1, 2, 3, 4);
	func(1.0, 20.0, 10);
}