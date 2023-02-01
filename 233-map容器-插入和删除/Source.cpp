#include<map>
#include<iostream>
#include<string>
using namespace std;

void PrintMap(const map<int, int>& mp) {
	for (map<int, int>::const_iterator citer = mp.begin();
		citer != mp.end();
		citer++) {
		cout << "Key: " << citer->first << " ";
		cout << "Value: " << citer->second << endl;
	}
	cout << endl;
}

void CheckMap(const map<int, int>& mp) {
	if (!mp.empty())
	{
		cout << "非空" << endl;
		cout << "大小：" << mp.size() << endl;
	}
	else
	{
		cout << "空" << endl;
	}
}

void test() {
	map<int, int>mp1;
	mp1.insert(make_pair(1, 2));
	mp1.insert(pair<int, int>(11, 12));
	mp1.insert(map<int, int>::value_type(21, 22));
	mp1[4] = 40;//不建议使用这种方式插入，因为这样的习惯会导致下面的错误
	PrintMap(mp1);
	//cout << mp1[5] << endl;//map中不存在键值为5的，应该打印失败，但是编译器为你创建了新的pair，默认value值是0
	//PrintMap(mp1);

	mp1.erase(mp1.begin());
	PrintMap(mp1);
	//mp1.begin() = mp1.end();//似乎是无效操作，被否决了
	PrintMap(mp1);
}

int main() {
	test();
}
