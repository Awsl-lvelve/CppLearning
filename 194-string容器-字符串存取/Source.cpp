#include<iostream>
#include<string>
using namespace std;

void test01() {
	string str = "Hello";
	cout << "str = " << str << endl;

	//��
	//ͨ��[]����
	//ͨ��at��ʽ����
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i);
	}
	cout << endl;


	//�޸ĵ����ַ�
	str[0] = 'X';
	cout << "str = " << str << endl;

	str.at(1) = 'E';

	cout << "str = " << str << endl;
};

int main() {
	test01();
}