#include<iostream>
using namespace std;

//�����ͨ�ͺ���ģ�嶼���Ե��ã����ȵ�����ͨ������
//���ǿ���ʹ�ÿ�ģ������б����ǿ�Ƶ���
//����ģ���������
//�������ģ����Ը��õ�ƥ�������ȵ��ú���ģ��

//���д��ģ�壬�Ͳ�Ҫ����ͨ������

void myPrint(int a, int b) {
	cout << "MyPrintNormFunc" <<  endl;
}

template<class T >
void myPrint(T a, T b) {
	cout << "MyPrintTemplateFunc" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "MyPrintTemplateFuncReload" << endl;
}

template<class T1,class T2>
void myPrint(T1 a, T2 b) {
	cout << "MultiTypeMyPrintTemplateFuncReload" << endl;
}

void test1() {
	int a = 10;
	int b = 20;
	//���ȵ�����ͨ����
	myPrint(a, b);
	//ǿ�Ƶ���
	myPrint<>(a, b);
	//ģ������
	myPrint(1, 2, 3);
	//���õ�ƥ��
	myPrint('a', 'b');
}




int main() {
	test1();
	return 0;
}