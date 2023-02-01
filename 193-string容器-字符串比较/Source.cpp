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

	//英文比较还有点意义，利用ASCII码对比
	//中文，差不多就比较相等与否
}

int main() {
	test01();
}