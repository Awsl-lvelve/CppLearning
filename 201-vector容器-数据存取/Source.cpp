#include<iostream>
#include<vector>
using namespace std;



void test() {
	vector<int>v1;
	for (int i = 0; i < 11; i++)
	{
		v1.push_back(i);
	}

	//����[]����
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	//����at����
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//����auto
	for (auto c : v1) {
		cout << c << " ";
	}
	cout << endl;
	//ͨ��������
	for (vector<int>::iterator iter = v1.begin();
		iter != v1.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//��һ��Ԫ��
	cout << v1.front() << endl;
	//���һ��Ԫ��
	cout << v1.back() << endl;

}

int main() {
	test();
}