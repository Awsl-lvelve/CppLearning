#include"Includes.h"
#include"SpeechManager.h"

int main() {
	SpeechManager sm(string("ABCDEFGHIJKL"),4,10);
	//sm.PrintSpeaker();
	while (true)
	{
		sm.ShowMenu();
		cout << "����������ѡ��" << endl;

		int choice=0;
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ����
			sm.StartSpeech();
			break;
		case 2://�鿴���������¼
			break;
		case 3://��ռ�¼
			break;
		case 0://�˳�ϵͳ
			sm.ExitSystem();
			break;
		default:
			system("cls");//����
			break;
		}


	}
}