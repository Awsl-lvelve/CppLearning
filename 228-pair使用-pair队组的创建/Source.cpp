#include<string>
#include<iostream>
using namespace std;

//两种创建方式
//pair<type, type>p(value1, value2);
//pair<type, type>p = make_pair(value1, value2);

void test() {
	pair<string, int>Person1("UltramanNexus", 99);

	cout << "姓名：" << Person1.first << endl;
	cout << "年龄：" << Person1.second << endl;

	pair<string, int>Person2=make_pair("UltramanZero", 999);

	cout << "姓名：" << Person2.first << endl;
	cout << "年龄：" << Person2.second << endl;

}

int main() {
	test();
}