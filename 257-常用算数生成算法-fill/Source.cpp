#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>

using namespace std;

void MyPrint(int v) {
	cout << v << " ";
}

void Test() {
	vector<int>v;

	v.resize(10);

	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), MyPrint);
}

int main() {
	Test();
}