#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//�ı��ļ� -�ļ����ı�ASCII�����ʽ�洢�ڼ������
//�������ļ� -�ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������

//1.����ͷ�ļ�

int main() {
	//2.����������
	ofstream ofs;

	//3.ָ���򿪷�ʽ
	ofs.open("./data.txt", std::ios::out);

	//4.д����
	ofs << "Ultraman Nexus" << endl;
	ofs << "Ultraman Ace" << endl;
	ofs << "Ultraman Zero " << endl;

	//5.�ر��ļ�
	ofs.close();



}