#include"workerManager.h"
#include"Worker.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"

#include<Windows.h>

//void test() {
//	Worker* worker = new Employee(1,"Nexus",10086);
//	worker->showInfo();
//	delete worker;
//
//	Worker* worker1 = new Manager(2, "Zero", 10087);
//	worker1->showInfo();
//	delete worker1;
//
//	Worker* worker2 = new Boss(3, "Seven", 10088);
//	worker2->showInfo();
//	delete worker2;
//}

int main() {
	wokerManager wkm;
	while (true)
	{
		wkm.showMenu();
		int selection;
		std::cin >> selection;

		switch (selection)
		{
		case 0://�˳�ϵͳ
			wkm.exitSystem();
			break;
		case 1://���ְ��
			wkm.addEmp();
			
			break;
		case 2://��ʾְ��
			wkm.showEmp();
			system("pause");
			system("cls");
			break;
		case 3://ɾ��ְ��
			wkm.delEntrance();
			system("pause");
			system("cls");
			break;
		case 4://�޸�ְ��
			break;
		case 5://����ְ��
			break;
		case 6://����ְ��
			break;
		case 7://����ļ�
			break;
		default:
			system("cls");
			break;
		}

	}

}