#include<map>
#include<iostream>
#include<string>
using namespace std;

void test() {
	map<int, int>m;
	m.insert(pair<int,int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	map<int, int>::iterator pos = m.find(3);//����key������key��Ӧ�ĵ�����

	if (pos!=m.end())
	{
		cout << "���ҵ�Ԫ��key=" << pos->first<<" ";
		cout << "value= " << pos->second<<endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	int num = m.count(3);//��mapҪôΪ0��ҪôΪ1
}

int main() {
	test();
}
