#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
}s3;//����Ҳ���Դ����ṹ��

void PrintStudent(const Student stu) {
	cout << stu.name << " " <<
		stu.age <<" "<<
		stu.score << endl;
}



int main() {
	//������ʽ1
	Student stu1{ "Ultraman",15,100 };
	//������ʽ2
	Student stu2;
	stu2.name = "Jake";
	stu2.age = 19;
	stu2.score = 100;


	//������ʽ3,��ǰ�棬���ַ�ʽ������ʹ��
	s3.name = "Sherry";
	s3.age = 14;
	s3.score = 88;

	PrintStudent(stu1);
	PrintStudent(stu2);
	
}