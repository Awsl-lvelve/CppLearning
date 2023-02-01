#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//文本文件 -文件以文本ASCII码的形式存储在计算机中
//二进制文件 -文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

//1.包含头文件

int main() {
	//2.创建流对象
	ofstream ofs;

	//3.指定打开方式
	ofs.open("./data.txt", std::ios::out);

	//4.写内容
	ofs << "Ultraman Nexus" << endl;
	ofs << "Ultraman Ace" << endl;
	ofs << "Ultraman Zero " << endl;

	//5.关闭文件
	ofs.close();



}