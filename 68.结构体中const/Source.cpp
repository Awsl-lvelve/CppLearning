#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};


//�������е��βθ�Ϊָ������
//�����ٿ���һ�ݽ�ʡ�ռ�
//����Ҫ�����޸�ָ���е�����
//const!
void Print(const Student* stu) {
	cout <<
		stu->name << " " <<
		stu->age << " " <<
		stu->score << endl;
}

int main()
{
	Student s{ "����",16,88 };
	Print(&s);
}


