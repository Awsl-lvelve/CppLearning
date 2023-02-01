#include<set>
#include<iostream>
using namespace std;

void PrintSet(const set<int>& iset) {
	for (set<int>::const_iterator citer = iset.begin();
		citer != iset.end();
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

	PrintSet(s1);
	set<int>::iterator iter = s1.find(1984);

	cout <<*iter << endl;

	int num = s1.count(1984);//对于set而言，这个结果要么为，要么为1
}

int main() {
	test01();
}