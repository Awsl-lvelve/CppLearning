#include"INCLUDES.h"
#include"SpeakManager.h"

int main() {
	//���������
	srand((unsigned int)time(NULL));

	SpeakManager sm;

	int choice = 0; //���ڴ洢�û�����


	while (true)
	{
		sm.ShowMenu();

		cout << "����������ѡ�� " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: // ��ʼ����
			sm.StartSpeech();
			break;
		case 2: //�鿴���������¼
			sm.ShowRecord();
			break;
		case 3:  //��ձ�����¼
			sm.ClearRecord();
			break;
		case 0:  //�˳�ϵͳ
			sm.ExitSystem();
			break;
		default:
			system("cls"); // ����
			break;
		}
	}


	system("pause");
	return 0;


}