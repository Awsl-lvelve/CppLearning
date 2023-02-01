#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//址传递
void ModiAge(Student* stu) {
	stu->age += 2;
}

//值传递
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
	Student s{ "张三",16,88 };

	Print(&s);

	ModiAge(s);

	Print(&s);

	ModiAge(&s);
	Print(&s);


}