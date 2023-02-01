#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

class Person {
public:
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
	string name_;
	int age_;
};

class GreaterFive {
public:
	bool operator()(int v) {
		return v > 5;
	}
};

template<class T>
void PrintVec(const vector<T>vec) {
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}


//find 查找指定元素，找到返回指定元素的迭代器，找不到返回end迭代器
//内置
void test01() {
	vector<int>v;

	for (int i = 1; i < 10; i++) { v.push_back(i); }
	PrintVec<int>(v);

	vector<int>::iterator iter = find_if(v.begin(), v.end(), GreaterFive());

	if (iter == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到元素：" << *iter << endl;
	}

}
class GreaterAge30 {
public:
	bool operator()(Person p) {
		return p.age_ > 30;
	}
};

void PrintVecPerson(const vector<Person>& pvec) {
	for (auto p : pvec) {
		cout << "编号：" << p.name_ << "  年龄：" << p.age_ << endl;
	}
	cout << endl;
}

//自定义类型
void test02() {
	vector<Person>v;

	string name_seed = "ABCDEFGHIJ";
	for (string::iterator iter = name_seed.begin();
		iter != name_seed.end();
		iter++) {
		string name = string("Person ") + *iter+string(" ");

		int age = rand() % 31 + 30;
		Person p(name, age);

		v.push_back(p);
	}

	vector<Person>::iterator iter =v.begin();
	PrintVecPerson(v);

	iter = find_if(v.begin(), v.end(),GreaterAge30() );

	if (iter == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到元素：" << iter->name_ << endl;
	}

}

int main() {
	test01();
	test02();
}