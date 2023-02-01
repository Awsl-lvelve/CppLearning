#include<list>
#include<iostream>
using namespace std;

//list<int>lst;
//list(beg, end);
//list(n, elem);
//list(const list& lst);

void PrintList(const list<int>& L) {
	for (list<int>::const_iterator ct=L.begin();
		ct!=L.end();
		ct++)
	{
		cout << *ct << " ";
	}
	cout << endl;
}

void test01() {
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	//遍历容器
	PrintList(L1);
	//迭代器构造
	list<int>L2(L1.begin(), L1.end());
	PrintList(L2);
	//拷贝构造
	list<int>L3(L2);
	PrintList(L3);
}

int main() {
	test01();
}
