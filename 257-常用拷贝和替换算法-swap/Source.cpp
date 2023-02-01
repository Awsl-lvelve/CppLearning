#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

void MyPrint(const int& val) {
	cout << val << " ";
}

void test() {
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	for_each(v1.begin(), v1.end(), MyPrint);
	cout << endl;
	
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << endl;
	
	swap(v1, v2);

	for_each(v1.begin(), v1.end(), MyPrint);
	cout << endl;

	for_each(v2.begin(), v2.end(), MyPrint);
	cout << endl;


}

int main() {
	test();
}