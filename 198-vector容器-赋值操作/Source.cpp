#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test() {
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printVec(v1);

	vector<int>v2;
	v2 = v1;
	printVec(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVec(v3);

	vector<int>v4;
	v4.assign(10, 1024);
	printVec(v4);
}

int main() {
	test();
}