#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

#include<numeric>

//À„¿€º∆∫Õ
//1+2+3+4+5+...+100
using namespace std;

void test() {
	vector<int>v;

	for (int i = 1; i < 101; i++)
	{
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);

	cout << total << endl;
}

int main() {
	test();
}