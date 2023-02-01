#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

//常用遍历算法 for_each

class Print {
public:
	void operator()(int v) {
		cout << v << " ";
	}
};

void VecPrint(const vector<int>& vec) {
	for (auto c : vec) {
		cout << c << " ";
	}
	cout << endl;
}

void PrintNorm(const int& val) {
	cout << val << " ";
}

void test01() {
	vector<int>v;
	for (int i = 0; i != 10; i++) {
		v.push_back(rand() % 10);
	}

	//VecPrint(v);
	for_each(v.begin(), v.end(), Print());//仿函数
	cout << endl;
	for_each(v.begin(), v.end(), PrintNorm);//普通

}

int main() {
	test01();
}