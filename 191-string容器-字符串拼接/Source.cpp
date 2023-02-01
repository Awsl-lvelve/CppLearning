#include<iostream>
#include<string>
using namespace std;

//string 字符串拼接
//string operator+=(const char *str)
//string operator+=(const char c)
//string operator+=(const string&str)

//string& append(const char *s)
//string& append(const char *s,int n)
//string& append(const string&s)
//string& append(const string&s，int pos, int n)

void test() {
	string str1 = "我";
	str1 += "是奥特曼";
	cout << "str1 = " << str1 << endl;

	string str2 = "我";
	str2 += 'c';
	cout << "str2 = " << str2 << endl;

	string str3 = "You have been invaded ";
	string strX3 = "by Dark Spirit";
	str3 += strX3;
	cout << "str3 = " << str3 << endl;

	string str4 = "奥特曼";
	string strx4 = "打败了伽坦杰厄";
	str4.append(strx4, 5);
	cout << "str4= " << str4 << endl;

}

int main() {
	test();
}