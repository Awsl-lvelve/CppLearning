#include"INCLUDES.h"
#include"SpeakManager.h"

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	SpeakManager sm;

	int choice = 0; //用于存储用户输入


	while (true)
	{
		sm.ShowMenu();

		cout << "请输入您的选择： " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: // 开始比赛
			sm.StartSpeech();
			break;
		case 2: //查看往届比赛记录
			sm.ShowRecord();
			break;
		case 3:  //清空比赛记录
			sm.ClearRecord();
			break;
		case 0:  //退出系统
			sm.ExitSystem();
			break;
		default:
			system("cls"); // 清屏
			break;
		}
	}


	system("pause");
	return 0;


}