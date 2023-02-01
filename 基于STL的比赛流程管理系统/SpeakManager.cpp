#include "SpeakManager.h"

SpeakManager::SpeakManager()
{
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();
}

void SpeakManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeakManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeakManager::~SpeakManager()
{
}

void SpeakManager::StartSpeech()
{
	this->SpeechDraw();

	this->SpeechContest();

	this->ShowScore();

	this->m_index++;

	this->SpeechDraw();

	this->SpeechContest();

	this->ShowScore();

	this->SaveRecord();

	//重置比赛
	this->InitSpeech();
	
	this->CreateSpeaker();

	this->LoadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

void SpeakManager::SpeechDraw()
{
	cout << "第 << " << this->m_index << " >> 轮比赛选手正在抽签" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签后演讲顺序如下： " << endl;

	vector<vector<int>>::iterator iter1 = this->m_speaker_id.begin()+(this->m_index-1);

	random_shuffle((*iter1).begin(), (*iter1).end());

	for (auto c : *iter1) {
		cout << c << " ";
	}
	cout << endl;
	cout << "--------------------------" << endl;
	system("pause");
	cout << endl;

}

void SpeakManager::ShowRecord()
{
	if (this->m_file_is_empty)
	{
		cout << "文件为空或者不存在！" << endl;
		system("pause");
		system("cls");
		return;

	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届" << endl
				<< "冠军编号：" << this->m_record[i][0] << " "
				<< "冠军姓名：" << this->m_record[i][1] << " "
				<< "首轮得分：" << this->m_record[i][2] << " "
				<< "次轮得分：" << this->m_record[i][3] << endl;
			cout<< "亚军编号：" << this->m_record[i][4] << " "
				<< "亚军姓名：" << this->m_record[i][5] << " "
				<< "首轮得分：" << this->m_record[i][6] << " "
				<< "次轮得分：" << this->m_record[i][7] << endl;
			cout << "亚军编号：" << this->m_record[i][8] << " "
				<< "亚军姓名：" << this->m_record[i][9] << " "
				<< "首轮得分：" << this->m_record[i][10] << " "
				<< "次轮得分：" << this->m_record[i][11] << endl;
			cout << endl;
		}
		cout << endl;
	}

}

void SpeakManager::ClearRecord()
{
	cout << "是否确定清空文件？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化容器和属性
		this->InitSpeech();

		//创建12名选手
		this->CreateSpeaker();

		//加载往届记录
		this->LoadRecord();

		cout << "清空成功！" << endl;
	}

}

void SpeakManager::InitSpeech()
{
	//this->m_speaker_id.resize(5);
	//this->m_speaker_id(vector<vector<int>>{5});

	int i = 3;
	this->m_speaker_id = vector<vector<int>>(i);
	
	//for (auto c : m_speaker_id) {
	//	c.resize(2);
	//}

	this->m_speaker_info.clear();

	this->m_index = 1;

	this->m_record.clear();
}

void SpeakManager::CreateSpeaker()
{
	string name_seed = "ABCDEFGHIJKL";


	for (int i=0;i!=name_seed.size();i++)
	{
		string name = string("选手") + name_seed[i];

		Speaker sp;
		sp.SetName(name);

		for (int i = 0; i < 2; i++) {
			sp.AppScore();
		}

	


		vector<vector<int>>::iterator iter = this->m_speaker_id.begin();

		iter->push_back(i+10001);

		//cout << sp.GetName() << " " << sp.GetScore(1) << " " << sp.GetScore(2)<<endl;

		this->m_speaker_info.insert(map<int, Speaker>::value_type(i + 10001, sp));
	}

}

void SpeakManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用追加的方式写文件

	vector<vector<int>>::iterator winner = this->m_speaker_id.end() - 1;//winner指向的是前三名


	for (auto c : *winner) {
		ofs << c << "," 
			<<this->m_speaker_info[c].GetName() <<"," 
			<< this->m_speaker_info[c].GetScore(1) << "," 
			<< this->m_speaker_info[c].GetScore(2) << ",";
	}
	ofs << endl;

	this->m_file_is_empty = false;

}

void SpeakManager::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->m_file_is_empty = true;
		cout << "文件不存在" << endl;
		return;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_file_is_empty = true;
		cout << "空文件" << endl;
		ifs.close();
		return;
	}

	this->m_file_is_empty = false;
	ifs.putback(ch);
	
	string data;
	int index = 0;
	while (ifs>>data)
	{
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);

			if (pos == -1) {
				//没有找到逗号
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void SpeakManager::ShowScore()
{
	cout << "------------------ 第" << this->m_index << "轮晋级选手信息如下： -------------------" << endl;
	vector<vector<int>>::iterator iter = this->m_speaker_id.begin() + this->m_index;

	for (auto c : *iter) {
		cout << "选手编号：" << c << " " <<
			"姓名：" << m_speaker_info[c].GetName() << " " <<
			"得分：" << m_speaker_info[c].GetScore(this->m_index)<<endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->ShowMenu();
}

void SpeakManager::SpeechContest()
{
	cout << "----------- 第" << this->m_index << " 轮比赛正式开始 --------------" << endl;

	//准备临时容器 存放小组成绩
	//分数作为key id作为value
	multimap<double, int, greater<double>> group_score;

	int num = 0;


	vector<vector<int>>::iterator src = this->m_speaker_id.begin() + (m_index - 1);

	for (auto c : *src) {
		num++;

		deque<double>d;

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;

			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());

		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		
		this->m_speaker_info[c].SetScore(this->m_index, avg);

		group_score.insert(make_pair(avg, c));

		if (num%6==0)
		{
			cout << "第" << num / 6 << "小组比赛名次： " << endl;
			for (multimap<double, int, greater<>>::iterator it = group_score.begin();
				it != group_score.end();
				it++) {
				cout << "编号：" << it->second << " "
					"姓名：" << m_speaker_info[it->second].GetName() << " "
					"成绩：" << m_speaker_info[it->second].GetScore(this->m_index)<<endl;

			}

			//取走前三
			int count = 0;

			cout << this->m_speaker_id.size() << endl;
			for (multimap<double, int, greater<>>::iterator it = group_score.begin();
				it != group_score.end(),count!=3;
				it++,count++) {
				vector<vector<int>>::iterator iter1 = this->m_speaker_id.begin() + this->m_index;
				iter1->push_back(it->second);
			}
			group_score.clear();
			cout << endl;

		}

	}

	cout << "------------------ 第" << this->m_index << "轮比赛完毕 --------------" << endl;
	system("pause");

}

