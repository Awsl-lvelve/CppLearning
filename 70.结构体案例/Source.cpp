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
	Student sArray[5];
};

void Print(Student* stu) {
	cout <<
		stu->name << " " <<
		stu->age << " " <<
		stu->score << endl;
}

void PrintTeacher(Teacher t) {
		cout << "id��" << t.id << endl <<
			"������" << t.name << endl <<
			"���䣺" << t.age << endl <<
			"ָ����ѧ����" <<endl;
		for (size_t i = 0; i < 5; i++)
		{
			Print(&t.sArray[i]);
		}
}

void AllocateSpace(Teacher tArray[], int len)
{
	string nameseed = "ABCDE";
	for (size_t i = 0; i < len; i++)
	{

		tArray[i].name = "Teacher_";
		tArray[i].name += nameseed[i];
		tArray[i].age = 33;
		string nameseed1 = "MNPQR";
		for (size_t j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = "Student_";
			tArray[i].sArray[j].name += nameseed[i];
			tArray[i].sArray[j].name += nameseed1[j];

			int random = rand() % 61 + 40;
			tArray[i].sArray[j].score = random;

			tArray[i].sArray[j].age = 21;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//����������ʦ������
	Teacher tArray[3];
	//ͨ����������ʦ����Ϣ�Լ�����ѧ����Ϣ��ֵ
	AllocateSpace(tArray,3);
	for (size_t i = 0; i < 3; i++)
	{
		PrintTeacher(tArray[i]);
	}
	

}

