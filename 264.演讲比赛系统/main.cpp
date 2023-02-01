#include"Includes.h"
#include"SpeechManager.h"

int main() {
	SpeechManager sm(string("ABCDEFGHIJKL"),4,10);
	//sm.PrintSpeaker();
	while (true)
	{
		sm.ShowMenu();
		cout << "请输入您的选择：" << endl;

		int choice=0;
		cin >> choice;

		switch (choice)
		{
		case 1://开始比赛
			sm.StartSpeech();
			break;
		case 2://查看往届比赛记录
			break;
		case 3://清空记录
			break;
		case 0://退出系统
			sm.ExitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}


	}
}