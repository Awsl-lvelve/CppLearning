#include<iostream>
#include<string>
using namespace std;

//string ��c++�����ַ�����string��������

//string��char*����
//char *��һ��ָ��
//string�Ǹ��࣬���з�װ��char*����������ַ�������һ��char*�͵�����

//�ص�
//string���ڲ���װ������Ա����
//find copy delete replace insert
//string ����char*��������ڴ棬���õ��ĸ���Խ������⣬�����ڸ���


//���캯��
//string()
//string(const char*)
//string(const string &str)
//string(int n, char c)

void test() {
	string s1;//Ĭ��
	
	const char* str = "Hello World!";

	string s2(str);

	cout << s2 << endl;
	
	string s3(s2);

	string str1 = string(10, 'a');
	cout << str1 << endl;

}

int main() {
	test();
}
