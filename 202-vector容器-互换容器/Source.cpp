#include<iostream>
#include<vector>
using namespace std;


//�൱��swap

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test() {
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i * i);
	}
	cout << "v1: ";
	printVec(v1);
	cout << "v2��";
	printVec(v2);

	v1.swap(v2);
	cout << "v1: ";
	printVec(v1);
	cout << "v2��";
	printVec(v2);
}

void test02() {
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�Ĵ�С��" << v1.size() << endl;

	v1.resize(3);

	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�Ĵ�С��" << v1.size() << endl;

	//v1ռ���˼�������
	vector<int>(v1).swap(v1);
	// vector<int>(v1) ����v1������һ����������x����v1Ŀǰ���õ�Ԫ��������
	//����
	//���������������ڴ��Ч��
	cout << "������" << endl;
	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�Ĵ�С��" << v1.size() << endl;
}


int main() {
	test02();
}