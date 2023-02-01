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

	//É¾³ı

	s1.erase(s1.begin());
	PrintSet(s1);

	//ÖØÔØ°æÉ¾³ı
	s1.erase(1984);
	PrintSet(s1);

	//Çå¿Õ
	s1.clear();
	PrintSet(s1);

}

int main() {
	test01();
}