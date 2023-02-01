#include<set>
#include<iostream>
using namespace std;


template<class T>
void PrintSet(const T& set) {
	for (auto c : set) {
		cout << c << " ";
	}
	cout << endl;
}

void test01() {
	set<int>s1;
	s1.insert(10);

	//cout << typeid(s1.insert(10)).name() << endl;

	pair<set<int>::const_iterator, bool>ret = s1.insert(10);
	if (ret.second==true)
	{
		cout << "插入成功！" << endl;
	}
	else
	{
		cout << "插入失败!" << endl;
	}


	multiset<int>ms1;
	ms1.insert(10);
	ms1.insert(10);
	ms1.insert(10);
	ms1.insert(10);

	PrintSet(ms1);
}



int main() {
	test01();
}