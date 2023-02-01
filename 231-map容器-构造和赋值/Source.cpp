#include<map>
#include<iostream>
#include<string>
using namespace std;

void PrintMap(const map<int,int>&mp) {
	for (map<int, int>::const_iterator citer = mp.begin();
		citer != mp.end();
		citer++) {
		cout << "Key: " << citer->first << " ";
		cout << "Value: " << citer->second << endl;
	}
}

void test() {
	map<int, int>mp1;

	mp1.insert(make_pair(1, 2));
	mp1.insert(make_pair(2, 3));
	mp1.insert(make_pair(3, 4));
	mp1.insert(make_pair(4, 5));

	PrintMap(mp1);
}

int main() {
	test();
}
