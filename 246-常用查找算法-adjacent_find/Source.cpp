#include<vector>
#include<string>
#include<iostream>
#include<functional>
#include<algorithm>

using namespace std;

class GreaterThree {
public:
	bool operator()(int val1,int val2) { return val1>3; }//����Ԫ��
};

void test01() {
	vector<int>v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	vector<int>::iterator iter = adjacent_find(v.begin(), v.end(),GreaterThree());
	if (iter==v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ظ�Ԫ�أ�" << *iter << endl;
	}
}

int main() {
	test01();
}