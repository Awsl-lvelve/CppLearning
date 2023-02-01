//���� vector
//�㷨 for_each
//������ vector<int>::iterator

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
void MyPrint(T val) {
	cout << val<<'\t';
}

void test() {
	//����һ��vector
	vector<int> ivec;
	//��������

	for (int i = 0; i < 15; i++)
	{
		ivec.push_back(i+1);
	}

	//ͨ����������������
	vector<int>::iterator fore=ivec.begin();
	//.begin ָ���һ��Ԫ��
	vector<int>::iterator rear = ivec.end();
	//.end ָ�����λ�õ���һ��λ��

	//��һ�ű�����ʽ
	/*while (fore!=rear)
	{
		cout << *fore << '\t';
		fore++;
	}*/

	//�ڶ��ֱ���
	/*for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << '\t';
	}*/

	//�����ֱ�����ʽ ʹ��STL�ṩ�ı����㷨
	for_each(fore, rear, MyPrint<int>);//���Կ���ģ��


}

int main() {
	test();
}