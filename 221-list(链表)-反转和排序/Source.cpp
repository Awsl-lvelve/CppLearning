#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;


void PrintList(const list<int>& L) {
	for (list<int>::const_iterator ct = L.begin();
		ct != L.end();
		ct++)
	{
		cout << *ct << " ";
	}
	cout << endl;
}

//
bool MyComp(int v1, int v2) {
	return v1 > v2;
}

void test() {
	list<int>lst;

	lst.push_back(20);
	lst.push_back(70);
	lst.push_back(10);
	lst.push_back(12);
	lst.push_back(38);

	PrintList(lst);

	lst.reverse();

	PrintList(lst);

	cout << "����֮ǰ: ";
	//���в�֧��������ʵ���������������֧�ֱ�׼�㷨
	//��֧��������ʵ������������������ڻ��ṩ�����㷨
	//sort(lst.begin(),lst.end());
	PrintList(lst);
	//lst.sort();//Ĭ������
	//cout << "����֮��";
	//PrintList(lst);

	lst.sort(MyComp);//��������ʵ�ֽ���
	cout << "����֮��";
	PrintList(lst);
}


int main() {
	test();
}