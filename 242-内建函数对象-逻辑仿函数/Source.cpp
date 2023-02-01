#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

void test() {
	vector<bool>v;

	for (int i = 0; i < 10; i++)
	{
		int b = rand() % 2;
		bool val = (b == 1 ? true : false);
		v.push_back(val);
	}

	for (auto c : v) {
		cout << c << " ";
	}
	cout << endl;

	vector<bool>v2;
	v2.resize(v.size());//要准备空间，否则是搬不进去的！！！！！！会报错！！！！

	//利用逻辑非，将容器v搬运到容器v2中，并执行取反操作
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());

	for (auto c : v2) {
		cout << c << " ";
	}
	cout << endl;
	//真的不错捏！！


}

int main() {
	test();
}