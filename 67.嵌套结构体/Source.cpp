#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

struct Teacher
{
	int id;
	string name;
	int age;
	Student stu;
};

void PrintTeacher(Teacher t) {
	cout << "id��" << t.id << endl <<
		"������" << t.name << endl <<
		"���䣺" << t.age << endl<<
		"ָ����ѧ����" <<	t.stu.name << endl;
}

int main()
{
	Student s1 = { "����",18,99 };
	Student s2 = { "����",20,99 };
	Teacher t{12,"����",28,s1};
	PrintTeacher(t);

	
}