#include<iostream>
using namespace std;



int* func()
{
	//�ڶ�����������
	int *p=new int(10);
	return p;
}

void test1() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	delete p;
	cout << *p << endl;//���ڷ������쳣��
}

void test2()
{
	int* p= new int[10];//���ص����׵�ַ�����п�����int*p����

	for (int i = 0; i <10; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<p[i]<<'\t';
	}

	delete[]p;//�ͷ�����Ҫ����������Ȼ�����


}



int main()
{
	
	test2();
	return 0;
}