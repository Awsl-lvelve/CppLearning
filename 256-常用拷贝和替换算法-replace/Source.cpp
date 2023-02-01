#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;
//replaceÌæ»»ËùÓĞÔªËØ

template<class T>
void MyPrint(const T& val) {
	cout << val << " ";
}

void test() {
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), MyPrint<int>);

	replace(v1.begin(), v1.end(), 9, 100000);
	for_each(v1.begin(), v1.end(), MyPrint<int>);

}

int main() {
	test();
}