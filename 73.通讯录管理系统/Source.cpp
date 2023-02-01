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
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出通讯录" << endl;
	cout << "**********" << endl;
}

struct PhoneBook
{
	int counter;
	Person contacts[MAX];
};

void AddPerson(PhoneBook* pb) {
	//判断通讯录是否已满
	if (pb->counter==MAX)
	{
		cout << "通讯录已满无法添加" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;

		string gender;
		cout << "请输入性别" << endl;
		cin >> gender;

		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;

		string telephone;
		cout << "请输入电话号码" << endl;
		cin >> telephone;

		string household;
		cout << "请输入家庭住址" << endl;
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
		cout << "通讯录中无记录" << endl;
	}
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			cout << "姓名：" << pb->contacts[i].name << endl;
			cout << "姓别：" << pb->contacts[i].gender << endl;
			cout << "年龄：" << pb->contacts[i].age << endl;
			cout << "电话号码：" << pb->contacts[i].telephoneNum << endl;
			cout << "家庭住址：" << pb->contacts[i].houseHold << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
};

int CheckIsExist(PhoneBook* pb, string name) {
	for (size_t i = 0; i < pb->counter; i++)
	{
		if (pb->contacts[i].name == name)//找到了
		{
			return i;//返回下标
		}
	}
	return -1;//没有找到
}

void DeletePerson(PhoneBook *pb) {
	cout << "请输入姓名" << endl;
	string name;
	cin >> name;
	int len = pb->counter;

	int pos = CheckIsExist(pb,name);

	if (pos==-1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "找到此人" << endl;
		for (size_t i = pos; i < len; i++)
		{
			pb->contacts[i] = pb->contacts[i + 1];
		}
		pb->counter--;
		cout << "删除完毕" << endl;
	}
	system("pause");
	system("cls");
}

void FindPerson(PhoneBook* pb) {
	cout << "请输入姓名" << endl;
	string name;
	cin >> name;

	int pos = CheckIsExist(pb, name);
	if (pos==-1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名：" << pb->contacts[pos].name << endl;
		cout << "姓别：" << pb->contacts[pos].gender << endl;
		cout << "年龄：" << pb->contacts[pos].age << endl;
		cout << "电话号码：" << pb->contacts[pos].telephoneNum << endl;
		cout << "家庭住址：" << pb->contacts[pos].houseHold << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Modi(PhoneBook* pb, int pos,int select)
{
	cout << "输入想修改的内容" << endl;
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
	cout << "请输入姓名" << endl;
	string name;
	cin >> name;

	int pos = CheckIsExist(pb, name);
	if (pos == -1)
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入你想修改的项目" << endl;
		cout << "1.姓名" << endl;
		cout << "2.性别" << endl;
		cout << "3.年龄" << endl;
		cout << "4.电话号码" << endl;
		cout << "5.住址" << endl;

		int select = -1;
		cin >> select;
		Modi(pb, pos, select);

		system("pause");
		system("cls");
	}
}

void ClearAll(PhoneBook* pb) {
	pb->counter=0;
	cout << "所有联系人已经清除" << endl;
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
			cout << "欢迎下次使用" << endl;
			return 0;
		case 1://添加联系人
			AddPerson(&pb);
			break;
		case 2://显示联系人
			ShowBook(&pb);
			break;
		case 3://删除联系人
			DeletePerson(&pb);
			break;
		case 4://查找联系人
			FindPerson(&pb);
			break;
		case 5://修改联系人
			ModiPerson(&pb);
			break;
		case 6://删除所有联系人
			ClearAll(&pb);
			break;
		default:
			break;
		}
	}


	return 0;
}
