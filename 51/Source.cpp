#include<iostream>
using namespace std;

//���ô��ݣ���ı�ԭֵ�����ǿ���
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//ֵ���ݣ�����ı�ԭֵ��ֻ�´��һ��
void Swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	Swap1(a, b);
	cout << a << " " << b << endl;
}