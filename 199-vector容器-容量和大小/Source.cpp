#include<iostream>
#include<vector>
using namespace std;

//empty() �ж������Ƿ�Ϊ��
//capacity() ��������
//size() ������Ԫ������
//reszie(int num) ����ָ����������Ϊnum�����߳��������Ĭ��ֵ
//����̣��򳬳�num��Ԫ�ر�ɾ��
//resize(int num,elem) ָ�����ֵ

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test01() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVec(v1);

	if (v1.empty())
	{
		//Ϊ�棬��������Ϊ��
		cout << "v1Ϊ�ա�" << endl;
	}
	else
	{
		cout << "v1��Ϊ�ա�" << endl;
		cout << "����: " << v1.capacity() << endl;
		cout << "Ԫ��������" << v1.size() << endl;
	}

	//v1.resize(15);//�������ָ���ı�ԭ������Ĭ����0���
	//v1.resize(15, 100);
	v1.resize(5);
	printVec(v1); //�������ָ���ı�ԭ���̣��������ֻᱻɾ��

}

int main() {
	test01();
}