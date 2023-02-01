#include<iostream>
#include<vector>
using namespace std;


//相当于swap

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test() {
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i * i);
	}
	cout << "v1: ";
	printVec(v1);
	cout << "v2：";
	printVec(v2);

	v1.swap(v2);
	cout << "v1: ";
	printVec(v1);
	cout << "v2：";
	printVec(v2);
}

void test02() {
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;

	v1.resize(3);

	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;

	//v1占用了极大容量
	vector<int>(v1).swap(v1);
	// vector<int>(v1) 利用v1创建了一个匿名对象x，用v1目前所用的元素来创建
	//互换
	//这样阔以起到收缩内存的效果
	cout << "互换后" << endl;
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
}


int main() {
	test02();
}