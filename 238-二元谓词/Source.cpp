#include<iostream>
using namespace std;
#include<vector>

//谓词：
//返回值为bool类型的仿函数为谓词
//如果operator()接受一个参数，为一元谓词
//如果operator()接受两个参数那么为二元谓词

class GreatFive {
	bool operator()(int v) {
		if (v > 5) return true;
		else return false;
	}
};

void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//GreatFive() 创建一个匿名函数对象！
	vector<int>::iterator iter= find_if(v.begin(), v.end(), GreatFive());
	if (iter==v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了大于5的" <<*iter<< endl;
	}
}