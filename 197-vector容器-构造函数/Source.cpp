#include<iostream>
#include<vector>
using namespace std;
//功能 类似于数组 aka单端数组
//与普通数组的区别
//数组是静态空间，vector阔以动态扩展
//动态扩展：不是在原有空间之后续接新空间，而是寻找更大的内存空间，将原始数据拷贝到新空间

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter=ivec.begin();
		iter!=ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test01() {
	vector<int>ivec;//默认构造

	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}

	printVec(ivec);

	//利用区间的形式
	vector<int>ivec1(ivec.begin(), ivec.end());
	printVec(ivec1);

	//n个elem的形式
	vector<int>ivec2(10, 100);//10 个100
	printVec(ivec2);

	//拷贝构造
	vector<int>ivec3(ivec2);
	printVec(ivec3);

	//vector<int>ivec1({ 1,2,3,5,6 });//有参构造


}

int main() {
	test01();
}