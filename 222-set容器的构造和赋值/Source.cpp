#include<set>
#include<iostream>
using namespace std;

void PrintSet(const set<int>& iset) {
	for (set<int>::const_iterator citer=iset.begin();
		citer!=iset.end();
		citer++)
	{
		cout << *citer << " ";
	}
	cout << endl;
}

void test01() {
	set<int>s1;

	s1.insert(19);
	s1.insert(84);
	s1.insert(1);
	s1.insert(9);
	s1.insert(8);
	s1.insert(4);
	s1.insert(1984);
	
	//set容器：在元素插入时，被排序
	//set容器不允许插入重复值
	PrintSet(s1);

	//拷贝构造
	set<int>s2(s1);
	PrintSet(s2);


}

int main() {
	test01();
}