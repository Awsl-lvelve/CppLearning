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
		cout << "������" << citer->name_ << " ";
		cout << "���䣺" << citer->age_ << " ";
		cout << "��ߣ�" << citer->height_ << endl;
	}
	cout << endl;
}

//ָ���������
bool PersonComp(const Person&p1,const Person&p2) {
	//������������
	if (p1.age_==p2.age_)
	{
		return p1.height_ > p2.height_;//������ͬ������߽���
	}
	else
	{
		return p1.age_ < p2.age_;//���䲻ͬ������������
	}
}

void test01() {
	Person p1("����", 45, 180);
	Person p2("����", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("�ŷ�", 35, 160);
	Person p5("����", 25, 190);

	list<Person>plst;

	plst.push_back(p1);
	plst.push_back(p2);
	plst.push_back(p3);
	plst.push_back(p4);
	plst.push_back(p5);


	cout << "����֮ǰ��";
	ListPrinter(plst);

	plst.sort(PersonComp);
	cout << "����֮��";
	ListPrinter(plst);

}

int main() {
	test01();
}