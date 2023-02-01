#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

//赋值仿函数？
class Transform {
public:
	int operator()(const int&v) { return v; }
};

//打印仿函数
class Print {
public:
	void operator()(const int&v) {
		cout << v << " ";
	}
};


void test01() {
	vector<int>ivec;

	for (int i = 0; i < 10; i++) {
		ivec.push_back(rand() % 100);
	}//填充元素

	vector<int>vTarget;
	vTarget.resize(ivec.size());//必须准备空间！

	//tranform(v1.beg,v1.end,v2.beg,Func);
	//单纯赋值而已，所以TransForm返回的是参数本身
	transform(ivec.begin(), ivec.end(), vTarget.begin(), Transform());
	//打印仿函数
	for_each(ivec.begin(), ivec.end(), Print());
}

int main() {
	test01();
}