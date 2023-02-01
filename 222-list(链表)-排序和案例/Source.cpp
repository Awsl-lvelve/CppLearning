#include<list>
#include<string>
#include<iostream>
using namespace std;

class Person
{
public:

	Person(string name,int age,int height):name_(name),age_(age),height_(height) {}

	string name_;
	int age_;
	int height_;
};

void ListPrinter(const list<Person>& plst) {
	for (list<Person>::const_iterator citer=plst.begin();
		citer!=plst.end();
		citer++)
	{
		cout << "姓名：" << citer->name_ << " ";
		cout << "年龄：" << citer->age_ << " ";
		cout << "身高：" << citer->height_ << endl;
	}
	cout << endl;
}

//指定排序规则
bool PersonComp(const Person&p1,const Person&p2) {
	//按照年龄升序
	if (p1.age_==p2.age_)
	{
		return p1.height_ > p2.height_;//年龄相同按照身高降序
	}
	else
	{
		return p1.age_ < p2.age_;//年龄不同按照年龄升序
	}
}

void test01() {
	Person p1("刘备", 45, 180);
	Person p2("刘备", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("张飞", 35, 160);
	Person p5("赵云", 25, 190);

	list<Person>plst;

	plst.push_back(p1);
	plst.push_back(p2);
	plst.push_back(p3);
	plst.push_back(p4);
	plst.push_back(p5);


	cout << "排序之前：";
	ListPrinter(plst);

	plst.sort(PersonComp);
	cout << "排序之后：";
	ListPrinter(plst);

}

int main() {
	test01();
}