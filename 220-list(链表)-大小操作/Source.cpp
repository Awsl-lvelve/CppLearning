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


void tst() {
	list<int>l1;

}