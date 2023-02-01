//容器 vector
//算法 for_each
//迭代器 vector<int>::iterator

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
void MyPrint(T val) {
	cout << val<<'\t';
}

void test() {
	//创建一个vector
	vector<int> ivec;
	//插入数据

	for (int i = 0; i < 15; i++)
	{
		ivec.push_back(i+1);
	}

	//通过迭代器访问数据
	vector<int>::iterator fore=ivec.begin();
	//.begin 指向第一个元素
	vector<int>::iterator rear = ivec.end();
	//.end 指向结束位置的下一个位置

	//第一张遍历方式
	/*while (fore!=rear)
	{
		cout << *fore << '\t';
		fore++;
	}*/

	//第二种遍历
	/*for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << '\t';
	}*/

	//第三种遍历方式 使用STL提供的遍历算法
	for_each(fore, rear, MyPrint<int>);//试试看用模板


}

int main() {
	test();
}