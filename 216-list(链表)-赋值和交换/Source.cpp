#include<iostream>
#include<list>
#include<string>
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

void test() {
	list<int>Ori{ 0,1,2,3,4,5,6 };

	list<int>lst;
	lst.assign(Ori.begin(), Ori.end());
	PrintList(lst);

	list<int>lst2(10,100);
	PrintList(lst2);

	list<int>lst3 = lst2;
	PrintList(lst3);

	swap(lst, lst2);
	PrintList(lst);
	PrintList(lst2);
}

int main() {
	test();
}