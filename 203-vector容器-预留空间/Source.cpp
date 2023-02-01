#include<iostream>
#include<vector>
using namespace std;


//预留空间的操作


void test() {
	vector<int>v;
	
	v.reserve(100000);//知道需要100000个数值
	//提前准备空间

	int num = 0;//统计开辟次数

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