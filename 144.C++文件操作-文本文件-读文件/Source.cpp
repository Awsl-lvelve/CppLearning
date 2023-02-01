#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//包含头文件

int main() {
	//2.创建流对象
	ifstream ifs;
	//3.打开文件，判断是否打开成功
	ifs.open("./data.txt",ios::in);
	
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return -1;
		//错误的文件路径、文件名称
	}

	//4.数据读取
		//第一种
	//char buf[2048] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种
	//char buf[4096] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}

	//第四种
	//一个一个读
	/*char c;
	while ((c=ifs.get())!=EOF)
	{
		cout << c << endl;
	}*/

	//5.关闭文件
	ifs.close();




}