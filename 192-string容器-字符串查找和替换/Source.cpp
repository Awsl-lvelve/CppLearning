#include<iostream>
#include<string>
using namespace std;

//int find(const string&str,int pos=0)const //str第一次出现的位置，默认从pos开始
//

//1.查找
void test01() {
	string str1 = "abcdefgde";
	int pos = str1.find("de");
	cout << "pos = " << pos << endl;

	int pos1 = str1.find("df");
	if (pos1==-1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos1 << endl;
	}

	//rfind 是从右往左找
	pos = str1.rfind("de");
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

}


//2.替换

void test02() {
	string str2 = "abcdefg";
	cout << "str=" << str2 << endl;
	//从1号位置起，三个字符替换为“1111”
	str2.replace(1, 3, "1111");
	cout << "str=" << str2 << endl;
}

int main() {
	//test01();
	test02();

}