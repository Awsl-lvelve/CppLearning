#include<string>
#include<iostream>
using namespace std;

//���ִ�����ʽ
//pair<type, type>p(value1, value2);
//pair<type, type>p = make_pair(value1, value2);

void test() {
	pair<string, int>Person1("UltramanNexus", 99);

	cout << "������" << Person1.first << endl;
	cout << "���䣺" << Person1.second << endl;

	pair<string, int>Person2=make_pair("UltramanZero", 999);

	cout << "������" << Person2.first << endl;
	cout << "���䣺" << Person2.second << endl;

}

int main() {
	test();
}