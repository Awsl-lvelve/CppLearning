#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

template<class T>
void PrintVec(const vector<T>& v) {
	for (auto c : v) {
		cout << c <<" ";
	}
	cout << endl;
}

template<class T>
class MyPrint {
public:
	bool operator()(T val) {
		cout << val < " ";
	}
};

class Person {
public:
	string name_;
	int age_;

	bool operator==(const Person& p) {

		if (this->age_ == p.age_)
		{

			return true;
		}
		else
		{
			return false;
		}

	}

	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
};

ostream& operator<<(ostream& out, const Person& p) {
	out << "–’√˚£∫" << p.name_ << " " << "ƒÍ¡‰£∫" << p.age_<<" ";
	return out;
}

void test01() {
	vector<int>vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	PrintVec(vec);
	random_shuffle(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), MyPrint<Person>());
;
}

void test02() {
	Person p1(string("’≈∑…"), 19);
	Person p2(string("πÿ”"), 18);
	Person p3(string("’‘‘∆"), 17);
	Person p4(string("¡ı±∏"), 16);
	Person p5(string("÷Ó∏¡¡"), 16);

	vector<Person>v;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	PrintVec(v);
	random_shuffle(v.begin(), v.end());
	PrintVec(v);
}

int main() {
	test02();
}