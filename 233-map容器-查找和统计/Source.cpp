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

	map<int, int>::iterator pos = m.find(3);//查找key，返回key对应的迭代器

	if (pos!=m.end())
	{
		cout << "查找到元素key=" << pos->first<<" ";
		cout << "value= " << pos->second<<endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	int num = m.count(3);//对map要么为0，要么为1
}

int main() {
	test();
}
