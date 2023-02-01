#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;


template<class T>
void PrintVec(const vector<T>& vec) {
	for (auto c : vec) {
		cout << c << " ";
	}
	cout << endl;
}

template<class T>
class MyPrint {
public:
	void operator()(const T& val) {
		cout << val << " ";
	}
};

//merge方法，操作两个有序的容器，合并于另一个容器中
void test
() {
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVec(v1);

	vector<int>v2;
	for (int i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}
	PrintVec(v2);
	
	vector<int>v3;
	v3.resize(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for_each(v3.begin(), v3.end(), MyPrint<int>());

	//PrintVec(v3);

}

int main() {
	test();
}