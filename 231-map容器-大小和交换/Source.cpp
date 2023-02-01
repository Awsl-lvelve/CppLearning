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
		cout<<"大小："<< mp.size() << endl;
	}
	else
	{
		cout << "空" << endl;
	}
}

void test() {
	map<int, int>mp1;
	CheckMap(mp1);
	mp1.insert(make_pair(1, 2));
	mp1.insert(make_pair(2, 3));
	mp1.insert(make_pair(3, 4));
	mp1.insert(make_pair(4, 5));
	CheckMap(mp1);


	map<int, int>mp2;
	CheckMap(mp2);
	mp2.insert(make_pair(11, 12));
	mp2.insert(make_pair(12, 13));
	mp2.insert(make_pair(13, 14));
	mp2.insert(make_pair(14, 15));
	mp2.insert(make_pair(15, 16));
	CheckMap(mp2);

	//cout << "map1大小：" << mp1.size() << endl;
	//cout << "map2大小：" << mp2.size() << endl;
	cout << "交换之前map1" << endl;
	PrintMap(mp1);
	cout << "交换之前map2" << endl;
	PrintMap(mp2);

	mp1.swap(mp2);

	cout << "交换之后map1" << endl;
	PrintMap(mp1);
	cout << "交换之后map2" << endl;
	PrintMap(mp2);

}

int main() {
	test();
}
