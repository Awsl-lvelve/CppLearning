#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//�������ļ� д�ļ�
//���ļ����в���������ѡ��ʹ��c����ַ�������Ҫ��c++��string��

class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test01() {
	ofstream ofs;


	ofs.open("./data.txt", ios::binary|ios::out);

	Person p{ "������",114514 };

	ofs.write((const char*)( & p),sizeof(Person));

	ofs.close();



}

int main() {
	test01();

}
