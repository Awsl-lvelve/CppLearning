#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;


void MyPrint(int v) {
	cout << v << " ";
}

//求有序序列的并集


void test() {
	vector<int>v1;
	vector<int>v2;

	for(int i = 0; i != 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>Targert;

	Targert.resize(v1.size() + v2.size());

	vector<int>::iterator iterEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), Targert.begin());

	for_each(Targert.begin(), iterEnd, MyPrint);
}

int main() {
	test();
}