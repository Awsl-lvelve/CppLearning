#include<iostream>
#include<string>
using namespace std;
constexpr auto MAX = 1000;;

struct Person
{
	string name;
	string gender;
	int age;
	string telephoneNum;
	string houseHold;
};

void ShowMenu() {
	cout << "**********" << endl;
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
	cout << "**********" << endl;
}

struct PhoneBook
{
	int counter;
	Person contacts[MAX];
};

void AddPerson(PhoneBook* pb) {
	//�ж�ͨѶ¼�Ƿ�����
	if (pb->counter==MAX)
	{
		cout << "ͨѶ¼�����޷����" << endl;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;

		string gender;
		cout << "�������Ա�" << endl;
		cin >> gender;

		int age = 0;
		cout << "����������" << endl;
		cin >> age;

		string telephone;
		cout << "������绰����" << endl;
		cin >> telephone;

		string household;
		cout << "�������ͥסַ" << endl;
		cin >> household;

		Person p;
		p.name = name;
		p.gender = gender;
		p.age = age;
		p.houseHold = household;
		p.telephoneNum = telephone;

		pb->contacts[pb->counter] = p;
		pb->counter++;
	}
	system("cls");
}

void ShowBook(PhoneBook *pb) {
	int len = pb->counter;
	if (len==0)
	{
		cout << "ͨѶ¼���޼�¼" << endl;
	}
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			cout << "������" << pb->contacts[i].name << endl;
			cout << "�ձ�" << pb->contacts[i].gender << endl;
			cout << "���䣺" << pb->contacts[i].age << endl;
			cout << "�绰���룺" << pb->contacts[i].telephoneNum << endl;
			cout << "��ͥסַ��" << pb->contacts[i].houseHold << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
};

int CheckIsExist(PhoneBook* pb, string name) {
	for (size_t i = 0; i < pb->counter; i++)
	{
		if (pb->contacts[i].name == name)//�ҵ���
		{
			return i;//�����±�
		}
	}
	return -1;//û���ҵ�
}

void DeletePerson(PhoneBook *pb) {
	cout << "����������" << endl;
	string name;
	cin >> name;
	int len = pb->counter;

	int pos = CheckIsExist(pb,name);

	if (pos==-1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "�ҵ�����" << endl;
		for (size_t i = pos; i < len; i++)
		{
			pb->contacts[i] = pb->contacts[i + 1];
		}
		pb->counter--;
		cout << "ɾ�����" << endl;
	}
	system("pause");
	system("cls");
}

void FindPerson(PhoneBook* pb) {
	cout << "����������" << endl;
	string name;
	cin >> name;

	int pos = CheckIsExist(pb, name);
	if (pos==-1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������" << pb->contacts[pos].name << endl;
		cout << "�ձ�" << pb->contacts[pos].gender << endl;
		cout << "���䣺" << pb->contacts[pos].age << endl;
		cout << "�绰���룺" << pb->contacts[pos].telephoneNum << endl;
		cout << "��ͥסַ��" << pb->contacts[pos].houseHold << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Modi(PhoneBook* pb, int pos,int select)
{
	cout << "�������޸ĵ�����" << endl;
	string clause;
	cin >> clause;

	switch (select)
	{
	case 1:
		pb->contacts[pos].name = clause;
		break;
	case 2:
		pb->contacts[pos].gender = clause;
		break;
	case 3:
		pb->contacts[pos].age= stoi(clause);
		break;
	case 4:
		pb->contacts[pos].telephoneNum = clause;
		break;
	case 5:
		pb->contacts[pos].houseHold = clause;
		break;
	default:
		break;
	}
}

void ModiPerson(PhoneBook *pb) {
	cout << "����������" << endl;
	string name;
	cin >> name;

	int pos = CheckIsExist(pb, name);
	if (pos == -1)
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�����������޸ĵ���Ŀ" << endl;
		cout << "1.����" << endl;
		cout << "2.�Ա�" << endl;
		cout << "3.����" << endl;
		cout << "4.�绰����" << endl;
		cout << "5.סַ" << endl;

		int select = -1;
		cin >> select;
		Modi(pb, pos, select);

		system("pause");
		system("cls");
	}
}

void ClearAll(PhoneBook* pb) {
	pb->counter=0;
	cout << "������ϵ���Ѿ����" << endl;
	system("pause");
	system("cls");
}

int main() {
	PhoneBook pb;
	pb.counter = 0;
	int select = 0;

	while (true)
	{
		ShowMenu();

		cin >> select;

		switch (select)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		case 1://�����ϵ��
			AddPerson(&pb);
			break;
		case 2://��ʾ��ϵ��
			ShowBook(&pb);
			break;
		case 3://ɾ����ϵ��
			DeletePerson(&pb);
			break;
		case 4://������ϵ��
			FindPerson(&pb);
			break;
		case 5://�޸���ϵ��
			ModiPerson(&pb);
			break;
		case 6://ɾ��������ϵ��
			ClearAll(&pb);
			break;
		default:
			break;
		}
	}


	return 0;
}
