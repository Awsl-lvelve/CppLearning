#include<iostream>
using namespace std;

struct Student
{
	string name;
};

class Teacher {
	string name;
};

int main() {
	Student s;
	s.name = "Ultraman";

	Teacher t;
	t.name = "Hover";//class Ĭ�Ϸ���Ȩ��Ϊprivate��
}