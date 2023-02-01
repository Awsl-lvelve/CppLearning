#include<iostream>
#include<vector>
#include<functional>
using namespace std;

class Person {
public:
	Person(const string& name, const int& age) {
		this->name_ = name;
		this->age_ = age;
	}

	void ModiPerson(const string& name, const int& age) {
		this->name_ = name;
		this->age_ = age;
	}

	bool operator==(const Person& p) {
		if (this->name_==p.name_&&this->age_==p.age_)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string name_;
	int age_;
};

ostream& operator<<(ostream& out, const Person& p) {
	out << "姓名：" << p.name_ << " ";
	out << "年龄：" << p.age_ << endl;

	return out;
}

void test01() {
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	string name = "eeee";
	int age = 18;
	Person p5(name, age);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	vector<Person>::iterator iter = find(v.begin(), v.end(), p1);

	if (iter==v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到元素：" << *iter << endl;
	}

}

int main() {
	test01();
}