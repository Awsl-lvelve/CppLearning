#include<set>
#include<iostream>
using namespace std;

class Person {
public:

	Person(string name, int age, int height) :name_(name),age_(age),height_(height) {}

	string name_;
	int age_;
	int height_;

};

class MyComp {
public:
	bool operator()(const Person &v1,const Person& v2) const {
		if (v1.age_==v2.age_)
		{
			//年龄相同时
			//按照身高升序
			return v1.height_ < v2.height_;
		}
		else
		{
			//按照年龄降序
			return v1.age_ > v2.age_;
		}
	}
};

void PrintSet(const set<Person,MyComp>&pset) {
	for (set<Person,MyComp>::const_iterator citer=pset.begin();
		citer!=pset.end();
		citer++)
	{
		cout << citer->name_ << " " << citer->age_ << " " << citer->height_<<endl;
	}
}


void test() {
	Person p1("刘备", 45, 180);
	Person p2("关羽", 45, 200);
	Person p3("孙权", 40, 170);
	Person p4("张飞", 35, 160);
	Person p5("赵云", 25, 190);

	set<Person, MyComp>s1;
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);

	PrintSet(s1);
}

int main() {
	test();

}