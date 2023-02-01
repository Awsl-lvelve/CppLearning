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
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeakManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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

	//���ñ���
	this->InitSpeech();
	
	this->CreateSpeaker();

	this->LoadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void SpeakManager::SpeechDraw()
{
	cout << "�� << " << this->m_index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£� " << endl;

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
		cout << "�ļ�Ϊ�ջ��߲����ڣ�" << endl;
		system("pause");
		system("cls");
		return;

	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "��" << i + 1 << "��" << endl
				<< "�ھ���ţ�" << this->m_record[i][0] << " "
				<< "�ھ�������" << this->m_record[i][1] << " "
				<< "���ֵ÷֣�" << this->m_record[i][2] << " "
				<< "���ֵ÷֣�" << this->m_record[i][3] << endl;
			cout<< "�Ǿ���ţ�" << this->m_record[i][4] << " "
				<< "�Ǿ�������" << this->m_record[i][5] << " "
				<< "���ֵ÷֣�" << this->m_record[i][6] << " "
				<< "���ֵ÷֣�" << this->m_record[i][7] << endl;
			cout << "�Ǿ���ţ�" << this->m_record[i][8] << " "
				<< "�Ǿ�������" << this->m_record[i][9] << " "
				<< "���ֵ÷֣�" << this->m_record[i][10] << " "
				<< "���ֵ÷֣�" << this->m_record[i][11] << endl;
			cout << endl;
		}
		cout << endl;
	}

}

void SpeakManager::ClearRecord()
{
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������������
		this->InitSpeech();

		//����12��ѡ��
		this->CreateSpeaker();

		//���������¼
		this->LoadRecord();

		cout << "��ճɹ���" << endl;
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
		string name = string("ѡ��") + name_seed[i];

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
	ofs.open("speech.csv", ios::out | ios::app); // ��׷�ӵķ�ʽд�ļ�

	vector<vector<int>>::iterator winner = this->m_speaker_id.end() - 1;//winnerָ�����ǰ����


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
		cout << "�ļ�������" << endl;
		return;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_file_is_empty = true;
		cout << "���ļ�" << endl;
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
				//û���ҵ�����
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
	cout << "------------------ ��" << this->m_index << "�ֽ���ѡ����Ϣ���£� -------------------" << endl;
	vector<vector<int>>::iterator iter = this->m_speaker_id.begin() + this->m_index;

	for (auto c : *iter) {
		cout << "ѡ�ֱ�ţ�" << c << " " <<
			"������" << m_speaker_info[c].GetName() << " " <<
			"�÷֣�" << m_speaker_info[c].GetScore(this->m_index)<<endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->ShowMenu();
}

void SpeakManager::SpeechContest()
{
	cout << "----------- ��" << this->m_index << " �ֱ�����ʽ��ʼ --------------" << endl;

	//׼����ʱ���� ���С��ɼ�
	//������Ϊkey id��Ϊvalue
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
			cout << "��" << num / 6 << "С��������Σ� " << endl;
			for (multimap<double, int, greater<>>::iterator it = group_score.begin();
				it != group_score.end();
				it++) {
				cout << "��ţ�" << it->second << " "
					"������" << m_speaker_info[it->second].GetName() << " "
					"�ɼ���" << m_speaker_info[it->second].GetScore(this->m_index)<<endl;

			}

			//ȡ��ǰ��
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

	cout << "------------------ ��" << this->m_index << "�ֱ������ --------------" << endl;
	system("pause");

}

