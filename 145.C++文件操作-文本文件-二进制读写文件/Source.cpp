#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//二进制文件 写文件
//对文件进行操作，还是选择使用c风格字符串，不要用c++的string！

class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test01() {
	ofstream ofs;


	ofs.open("./data.txt", ios::binary|ios::out);

	Person p{ "奥特曼",114514 };

	ofs.write((const char*)( & p),sizeof(Person));

	ofs.close();



}

int main() {
	test01();

}
