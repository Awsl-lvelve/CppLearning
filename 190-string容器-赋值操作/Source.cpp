#include<iostream>
#include<string>
using namespace std;

int main() {
	string str1;
	str1 = "Hello World";

	cout <<"str1 = " << str1 << endl;

	string str2 = str1;//�ַ���
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';//���ַ���ֵ,���ǲ������ַ���ʼ��

	string str4;
	str4.assign("Hello C++");//const char*
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("Hello World", 7);//ȡ�ַ�����ǰn���ַ�
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(10, 'a');
	cout << "str6 = " << str6 << endl;

	
}