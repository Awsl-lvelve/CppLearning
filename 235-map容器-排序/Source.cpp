#include<map>
#include<iostream>
#include<algorithm>
using namespace std;


class MyComp {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void PrintMap(const map<int, int, MyComp>& mp) {
	for (map<int, int>::const_iterator citer = mp.begin();
		citer != mp.end();
		citer++) {
		cout << "Key: " << citer->first << " ";
		cout << "Value: " << citer->second << endl;
	}
	cout << endl;
}

void test01() {
	map<int, int,MyComp>m;
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));

	PrintMap(m);
}

int main() {
	test01();
}