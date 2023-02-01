#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

template<class T>
void MyPrint(const T& val) {
	cout << val << " ";
}

void test01() {
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint<int>);

	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), MyPrint<int>);

}

int main() {
	test01();
}