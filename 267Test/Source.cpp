#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Foo
{
public:

	Foo() {
		this->vec = vector<vector<int>>(5);
	}

	vector<vector<int>>vec;
};


void tst01() {
	vector<vector<int>>v(5);

	vector<int>v1;

	//v.push_back(v1);

	vector<vector<int>>::iterator iter = v.begin();

	iter->push_back(100);

	cout << v.size() << endl;

	for (auto c : v) {
		for (auto d : c)
		{
			cout << d << " ";
		}
		cout << endl;
	}

	v.clear();


}

void tst02() {
	Foo f;
	vector<vector<int>>::iterator it = f.vec.begin();
	it->push_back(100);
	cout << f.vec.size() << endl;
	cout << f.vec.begin()->size() << endl;
}

int main() {
	tst02();

}