#include<iostream>
#include<string>
using namespace std;

//int find(const string&str,int pos=0)const //str��һ�γ��ֵ�λ�ã�Ĭ�ϴ�pos��ʼ
//

//1.����
void test01() {
	string str1 = "abcdefgde";
	int pos = str1.find("de");
	cout << "pos = " << pos << endl;

	int pos1 = str1.find("df");
	if (pos1==-1)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "pos = " << pos1 << endl;
	}

	//rfind �Ǵ���������
	pos = str1.rfind("de");
	if (pos == -1)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

}


//2.�滻

void test02() {
	string str2 = "abcdefg";
	cout << "str=" << str2 << endl;
	//��1��λ���������ַ��滻Ϊ��1111��
	str2.replace(1, 3, "1111");
	cout << "str=" << str2 << endl;
}

int main() {
	//test01();
	test02();

}