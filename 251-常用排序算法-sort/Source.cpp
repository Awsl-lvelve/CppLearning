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

ostream& operator<<(ostream& out, const Person& p) {
	out << "ÐÕÃû£º" << p.name_ << " " << "ÄêÁä£º" << p.age_ << endl;
	return out;
}

class AgeBtL {
public:
	bool operator()(const Person& p1,const Person&p2) {
		return p1.age_ > p2.age_;
	}
};

class BtoL {
public:
	bool operator()(const int& p1,const int&p2) {
		return p1 > p2;
	}
};

template<class T>
void PrintVec(const vector<T>& v) {
	for (auto c : v) {
		cout << c<<endl;
	}
	cout << endl;
}



void test() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 20);
	}
	PrintVec(v);
	sort(v.begin(), v.end(), BtoL());
	PrintVec(v);
}

void test02() {
	Person p1(string("ÕÅ·É"), 19);
	Person p2(string("¹ØÓð"), 18);
	Person p3(string("ÕÔÔÆ"), 17);
	Person p4(string("Áõ±¸"), 16);
	Person p5(string("Öî¸ðÁÁ"), 16);

	vector<Person>v;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	PrintVec(v);

}

int main() {
	test();
}