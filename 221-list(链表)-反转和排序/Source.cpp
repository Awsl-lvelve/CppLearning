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

	cout << "排序之前: ";
	//所有不支持随机访问迭代器的容器，不支持标准算法
	//不支持随机访问迭代器的容器，容器内会提供排序算法
	//sort(lst.begin(),lst.end());
	PrintList(lst);
	//lst.sort();//默认升序
	//cout << "排序之后：";
	//PrintList(lst);

	lst.sort(MyComp);//这样可以实现降序
	cout << "排序之后：";
	PrintList(lst);
}


int main() {
	test();
}