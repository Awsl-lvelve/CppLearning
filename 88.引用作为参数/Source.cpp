//���������˵�Ƕ�ָ�봫�ݲ�����һ���滻

#include<iostream>
using namespace std;

//�ᷢ���ı�
void myswap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 11;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	myswap(a, b);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}