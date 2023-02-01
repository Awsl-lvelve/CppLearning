#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>

using namespace std;

void PrintV(const vector<int>& v) {
	for (auto c:v)
	{
		cout << c << " ";
	}
}

void test() {
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 3);
	}

	vector<int>VTagret;
	VTagret.resize(min(v1.size(), v2.size()));

	//获取交集
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), VTagret.begin());
	
	PrintV(VTagret);

}


void main() {
	test();
}