#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

void Print(Student* stu) {
	cout <<
		stu->name << " " <<
		stu->age << " " <<
		stu->score << endl;
}

int main() {
	Student s{ "����",16,88 };

	Student* ps = &s;

	Print(ps);

	
}