#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

class Greater3K {
public:
	bool operator()(int val) {
		return val > 3000;
	}
};

class MyPrint {
public:
	void operator()(int test) {
		cout << test << endl;
		this->count_++;
	}
	MyPrint(int count) :count_(count) {}
	MyPrint() { this->count_ = 0; }

	int count_;
};

void test01() {
	vector<int>v;

	for (int i = 1; i < 10; i++) {
		v.push_back(i * 1000);
	}

	replace_if(v.begin(), v.end(), Greater3K(), 1000000);
	for_each(v.begin(), v.end(), MyPrint());

}

int main() {
	test01();
}