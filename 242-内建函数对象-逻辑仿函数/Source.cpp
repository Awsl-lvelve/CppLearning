#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

void test() {
	vector<bool>v;

	for (int i = 0; i < 10; i++)
	{
		int b = rand() % 2;
		bool val = (b == 1 ? true : false);
		v.push_back(val);
	}

	for (auto c : v) {
		cout << c << " ";
	}
	cout << endl;

	vector<bool>v2;
	v2.resize(v.size());//Ҫ׼���ռ䣬�����ǰ᲻��ȥ�ģ������������ᱨ��������

	//�����߼��ǣ�������v���˵�����v2�У���ִ��ȡ������
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());

	for (auto c : v2) {
		cout << c << " ";
	}
	cout << endl;
	//��Ĳ����󣡣�


}

int main() {
	test();
}