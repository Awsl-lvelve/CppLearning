//����ģ��
//
//template<typename T>
//template<class T>
//�����typename��class���Ի����滻

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;


//���ͽ���
//void Swap(int &a,int&b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////������������
//void Swap(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//}

template<class T>//����һ��ģ�壬���߱���������Ĵ��������T��Ҫ����
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

void test() {
	int a = 10;
	int b = 20;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	Swap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;


	double c = 14;
	double d = 15;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	Swap(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d<< endl;

	//ʹ��ģ����н���
	//�Զ������Ƶ�
	Swap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	//
	Swap<int>(a, b);//��ʽ��֪T������
}


int main() {
	test();
}