#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

void PrintStudent(const Student stu) {
	cout << stu.name << " " <<
		stu.age << " " <<
		stu.score << endl;
}

int main() {
	Student arr[3] = { {"����",18,99},{"����",19,99},{"������",20,98}};
	
	for (size_t i = 0; i < 3; i++)
	{
		PrintStudent(arr[i]);
	}


	return 0;
}