#include<iostream>
using namespace std;

int main() {
	int a = 100;
	double b = 90;

	int* pa = &a;
	double* pb = &b;
	//int* ����ָ���ռ�ÿռ�
	cout << sizeof(pa) << endl;
	//double* ����ָ���ռ�ÿռ�
	cout << sizeof(pb) << endl;

	//32bitϵͳ�£�ָ���СΪ4Byte
	//64bitϵͳ�£�ָ���СΪ8Byte

}