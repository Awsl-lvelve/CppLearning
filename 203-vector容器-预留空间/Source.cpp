#include<iostream>
#include<vector>
using namespace std;


//Ԥ���ռ�Ĳ���


void test() {
	vector<int>v;
	
	v.reserve(100000);//֪����Ҫ100000����ֵ
	//��ǰ׼���ռ�

	int num = 0;//ͳ�ƿ��ٴ���

	int* p = NULL;
	vector<int>counter;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
			counter.push_back(v.size());
		}
	}
	cout << num << endl;

	for (auto c:counter)
	{
		cout << c << " ";
	}
	cout << endl;
}

int main() {
	test();
}