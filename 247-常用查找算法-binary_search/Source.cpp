//二分查找法，针对有序序列
//查找元素是否存在！！！
#include<vector>
#include<algorithm>

using namespace std;

void test01() {
	vector<int>v;

	for (int i = 0; i <10;i++)
	{
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(), v.end(), 9);
	cout<<(ret)
}