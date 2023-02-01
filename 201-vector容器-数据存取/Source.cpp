#include<iostream>
#include<vector>
using namespace std;



void test() {
	vector<int>v1;
	for (int i = 0; i < 11; i++)
	{
		v1.push_back(i);
	}

	//利用[]访问
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	//利用at访问
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//利用auto
	for (auto c : v1) {
		cout << c << " ";
	}
	cout << endl;
	//通过迭代器
	for (vector<int>::iterator iter = v1.begin();
		iter != v1.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//第一个元素
	cout << v1.front() << endl;
	//最后一个元素
	cout << v1.back() << endl;

}

int main() {
	test();
}