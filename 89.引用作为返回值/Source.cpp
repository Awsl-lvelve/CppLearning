#include<iostream>
using namespace std;

//������Ϊ�����ķ���ֵ
//��Ҫ���ؾֲ����������ã�������

int& test()
{
	int a = 10;//�ֲ�����
	return a;
}

int& test1() {
	static int a = 10;//ȫ�������������֮���ͷ�
	return a;
}


int main()
{
	int& ref = test();
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;
	//Ҳ������΢������������ԣ�����;ֲ�������ָ��һ�£�΢��������ᱣ��

	int& ref1 = test1();
	cout << ref1 << endl;
	cout << ref1<< endl;


	//�������ÿ�����Ϊ��ֵ
	test1() = 1000;//!!!�е����أ�
	cout << ref1 << endl;
	cout << ref1 << endl;

}