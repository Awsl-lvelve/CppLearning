#include<iostream>
using namespace std;

//�������������������
//�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//�º���û�й̶�д�����ǳ����

class MyPrint
{
public:
	void operator()(string text) {
		cout << text << endl;
	}
};

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void MyPrint2(string str) {
	cout << str << endl;
}

void test01() {
	MyPrint myprint;
	myprint("Hello World");
	MyPrint2("hELLO WORLD");
}

void test02() {
	MyAdd myadd;
	cout << myadd(1, 2) << endl;

	//������������
	cout << MyAdd()(100, 100) << endl;
};

int main() {
	test01();
	test02();
}