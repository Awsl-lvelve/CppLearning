#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//ַ����
void ModiAge(Student* stu) {
	stu->age += 2;
}

//ֵ����
void ModiAge(Student stu) {
	stu.age += 3;
}


void Print(Student* stu) {
	cout <<
		stu->name << " " <<
		stu->age << " " <<
		stu->score << endl;
}


int main() {
	Student s{ "����",16,88 };

	Print(&s);

	ModiAge(s);

	Print(&s);

	ModiAge(&s);
	Print(&s);


}