#include<iostream>
using namespace std;

//���ã������������

int main()
{
	int a = 10;
	int& b = a;//����������һ������

	//ָ�����ͬһ���ڴ�
	cout << (int)&a << endl;
	cout << (int)&b << endl;

	//��a���޸ģ�Ҳ�Ƕ�b���޸�
}