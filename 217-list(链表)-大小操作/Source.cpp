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

void test01() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20); 
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);

	if (!l1.empty())
	{
		cout << "¿Õlist" << endl;
	}
	else
	{
		cout << "·Ç¿Õlist" << endl;
	}

	l1.resize(10, 1000);
	PrintList(l1);
	
}

int main() {
	test01();
}