#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//����ͷ�ļ�

int main() {
	//2.����������
	ifstream ifs;
	//3.���ļ����ж��Ƿ�򿪳ɹ�
	ifs.open("./data.txt",ios::in);
	
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return -1;
		//������ļ�·�����ļ�����
	}

	//4.���ݶ�ȡ
		//��һ��
	//char buf[2048] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	//�ڶ���
	//char buf[4096] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//������
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}

	//������
	//һ��һ����
	/*char c;
	while ((c=ifs.get())!=EOF)
	{
		cout << c << endl;
	}*/

	//5.�ر��ļ�
	ifs.close();




}