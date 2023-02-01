#include<set>
#include<iostream>
using namespace std;

//利用仿函数



class MyComp {
public:
	//本质是函数调用运算符的重载
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

template<class T>
void PrintSet(const T& set) {
	for (auto c : set) {
		cout << c << " ";
	}
	cout << endl;
}


void PrintSet1(const set<int, MyComp>& iset) {
	for (set<int,MyComp>::const_iterator citer = iset.begin();
		citer != iset.end();
		citer++) {
		cout << *citer << " ";
	}
	cout << endl;
}

void test01() {
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(70);
	s1.insert(90);
	PrintSet(s1);
	
	set<int,MyComp>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(70);
	s2.insert(90);
	PrintSet1(s2);
}

int main() {
	test01();
}