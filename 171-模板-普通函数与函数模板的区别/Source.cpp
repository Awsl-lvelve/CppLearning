#include<iostream>
using namespace std;


//��ͨ�����뺯��ģ�������
//1.��ͨ�������ÿ��Է�����ʽ����ת��
//2.����ģ�� ���Զ������Ƶ� �����Է�����ʽ����ת��
//3.����ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת��

//��ͨ����
int myAdd01(int a,int b) {
	return a + b;
}

template<class T>
int myAdd02(T a, T b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;

	cout << myAdd01(a, b) << endl;

	char c = 'c';
	cout << myAdd01(10, c) << endl;
	//�������������ͨ��������ʱ������ʽ����ת��
}

void test02() {
	int a = 10;
	int b = 20;

	cout << myAdd02(a, b) << endl;

	char c = 'c';
	//cout << myAdd02(10, c) << endl;
	//����ģ����ʹ���Զ������Ƶ�ʱ�򣬲��ᷢ����ʽ����ת��
}

void test03() {
	int a = 10;
	int b = 20;

	cout << myAdd02(a, b) << endl;

	char c = 'c';
	cout << myAdd02<int>(10, c) << endl;
	//����ģ����ʹ���Զ������Ƶ�ʱ����ʽָ������ʱ�����Է�����ʽ����ת��
}



int main() {
	//test01();


}