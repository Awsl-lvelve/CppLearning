#include<iostream>
#include<string>
using namespace std;

void test01() {
	string str1 = "hello";
	string str2 = "hello";

	if (str1.compare(str2)==0)
	{
		cout << "str1=str2" << endl;
	}
	else if(str1.compare(str2)>0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}

	//Ӣ�ıȽϻ��е����壬����ASCII��Ա�
	//���ģ����ͱȽ�������
}

int main() {
	test01();
}