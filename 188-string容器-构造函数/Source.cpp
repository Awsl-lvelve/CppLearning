#include<iostream>
#include<string>
using namespace std;

//string 是c++风格的字符串，string本质是类

//string和char*区别
//char *是一个指针
//string是个类，类中封装了char*，管理这个字符串，是一个char*型的容器

//特点
//string类内部封装了许多成员方法
//find copy delete replace insert
//string 管理char*所分配的内存，不用担心复制越界等问题，由类内负责


//构造函数
//string()
//string(const char*)
//string(const string &str)
//string(int n, char c)

void test() {
	string s1;//默认
	
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
