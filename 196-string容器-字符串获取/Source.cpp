#include<iostream>
#include<string>
using namespace std;

void test01() {
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "str= " << str << endl;
	cout << "subStr= " << subStr << endl;
}

void test02() {
	string email = "Hello@sina.com";

	//�������ȡ �û�����Ϣ

	//��ȡ@���ŵ�λ��
	int pos = email.find('@');
	string userName = email.substr(0, pos);
	cout << userName << endl;
};

int main() {
	test02();
}
