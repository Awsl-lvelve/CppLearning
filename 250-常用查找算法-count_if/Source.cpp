#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

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

class GreaterThree {
public:
	bool operator()(int v) {
		return v > 3;
	}
};


class AgeOlderThan17 {
public:
	bool operator()(const Person& p) {
		if (p.age_>17)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test01() {
	vector<int>v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	int num = count_if(v.begin(), v.end(), GreaterThree());
	cout << num << endl;

}

void test02() {
	vector<Person>p;

	Person p1(string("ÕÅ·É"), 19);
	Person p2(string("¹ØÓğ"), 18);
	Person p3(string("ÕÔÔÆ"), 17);
	Person p4(string("Áõ±¸"), 16);
	Person p5(string("Öî¸ğÁÁ"), 16);

	vector<Person>v;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	int num = count_if(v.begin(), v.end(), AgeOlderThan17());
	cout << num << endl;
}


int main() {
	test01();
	test02();
}