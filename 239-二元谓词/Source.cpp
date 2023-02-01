#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyComp {
public :
	bool operator()(int i, int j) {
		if (i>j)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void Print(const vector<int>& vec) {
	for (auto c:vec)
	{
		cout << c << " ";
	}
	cout << endl;
}

void test() {
	vector<int>v;

	for (int i = 1; i <6 ; i++)
	{
		v.push_back(rand()%100);
	}
	Print(v);
	sort(v.begin(), v.end(), MyComp());
	Print(v);
}

int main() {
	test();
}