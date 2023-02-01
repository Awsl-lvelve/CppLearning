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
	cout << "id：" << t.id << endl <<
		"姓名：" << t.name << endl <<
		"年龄：" << t.age << endl<<
		"指导的学生：" <<	t.stu.name << endl;
}

int main()
{
	Student s1 = { "张三",18,99 };
	Student s2 = { "李四",20,99 };
	Teacher t{12,"老王",28,s1};
	PrintTeacher(t);

	
}