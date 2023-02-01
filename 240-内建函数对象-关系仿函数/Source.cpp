#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

void PrintVec(const vector<int>&vec) {
	for (auto c : vec) {
		cout << c << " ";
	}
	cout << endl;
}



void test() {
	vector<int>v;
	for (int i = 0; i < 12; i++)
	{
		v.push_back(rand() % 100);
	}
	PrintVec(v);

	sort(v.begin(), v.end(), greater<int>());
	PrintVec(v);
}

int main() {
	test();
}