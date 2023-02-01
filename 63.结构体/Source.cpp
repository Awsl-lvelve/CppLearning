#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
}s3;//这样也可以创建结构体

void PrintStudent(const Student stu) {
	cout << stu.name << " " <<
		stu.age <<" "<<
		stu.score << endl;
}



int main() {
	//创建方式1
	Student stu1{ "Ultraman",15,100 };
	//创建方式2
	Student stu2;
	stu2.name = "Jake";
	stu2.age = 19;
	stu2.score = 100;


	//创建方式3,看前面，这种方式不建议使用
	s3.name = "Sherry";
	s3.age = 14;
	s3.score = 88;

	PrintStudent(stu1);
	PrintStudent(stu2);
	
}