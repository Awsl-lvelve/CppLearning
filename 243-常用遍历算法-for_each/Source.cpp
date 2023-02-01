#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

//���ñ����㷨 for_each

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
	for_each(v.begin(), v.end(), Print());//�º���
	cout << endl;
	for_each(v.begin(), v.end(), PrintNorm);//��ͨ

}

int main() {
	test01();
}