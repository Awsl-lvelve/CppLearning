#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};


//将函数中的形参改为指针类型
//不会再拷贝一份节省空间
//不过要避免修改指针中的内容
//const!
void Print(const Student* stu) {
	cout <<
		stu->name << " " <<
		stu->age << " " <<
		stu->score << endl;
}

int main()
{
	Student s{ "张三",16,88 };
	Print(&s);
}


