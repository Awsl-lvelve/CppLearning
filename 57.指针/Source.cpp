#include<iostream>

using namespace std;

int main() {
	int a = 100;
	int b = 90;

	//ָ���ʹ��
	int* pa = &a;
	int* pb = &b;

	//*pointer �����ò��� ��õ�ַ�д洢�ĵ�ַ

	cout << *pa + *pb << endl;
}