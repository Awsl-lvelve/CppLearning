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

	//bool operator==(const Person &p) {
	//	
	//	if (this->age_ == p.age_)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	Person(string name,int age){
		this->name_ = name;
		this->age_ = age;
	}
};


void test() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i*10);
		v.push_back(i * 10);
	}

	int counter = count(v.begin(), v.end(), 20);
	cout << counter << endl;
}

void test02() {
	Person p1(string("ÕÅ·É"), 19);
	Person p2(string("¹ØÓð"), 18);
	Person p3(string("ÕÔÔÆ"),17);
	Person p4(string("Áõ±¸"), 16);

	Person p5(string("Öî¸ðÁÁ"),16);

	vector<Person>v;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	int num = count(v.begin(), v.end(), p5);

	cout << num << endl;

}

int main() {
	test02();
}