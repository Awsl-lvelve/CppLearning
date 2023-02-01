#include"SpeechManager.h"

SpeechManager::SpeechManager(const string& name_seed, const int& total_round, const int& commentator_num)
{
	//��ʼ������������
	this->InitSpeech(name_seed,total_round,commentator_num);
	//�������ӳ��ȴ���
	this->CreateSpeaker(name_seed,total_round);

}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::CreateSpeaker(string name_seed,int total_round)
{
		
	int index_maximum = name_seed.size();//����name_seedȷ������ѡ������
	int indexer = 0;//�α꣬��ɲ���ѡ��������һ����

	int i = 0;
	for (i = 0; i < name_seed.size(); i++) {
		string name = string("ѡ��") + name_seed[i];

		Speaker sp;

		sp.SetName(name);

		//����round���������÷���ȫΪ0
		for (int i = 0; i < total_round; i++) {
			sp.InitScoreRecs(0.0);
		}

		this->round_recorder_.begin()->push_back(i + 10001);

		this->speaker_.insert(pair<int, Speaker>(indexer + 10001, sp));
		++indexer;

	}

	//for (auto c : *this->round_recorder_.begin()) {
	//	cout << c << " ";
	//}

	//for (string::iterator iter=name_seed.begin();
	//	iter!=name_seed.end();
	//	iter++)
	//{
	//	
	//	string name = string("ѡ��") + *iter;

	//	Speaker sp;

	//	sp.SetName(name);
	//	for (int i = 0; i < total_round;i++) {
	//		sp.AppScore(0.0);
	//	}//����round���������÷���ȫΪ0

	//	this->round_recorder.begin()->push_back(indexer+10001);

	//	//ѡ�ֱ�� �Լ���Ӧ��ѡ�ַ���map������
	//	this->speaker_.insert(pair<int, Speaker>(indexer + 10001, sp));
	//	++indexer;
	//}
}

void SpeechManager::PrintRound(vector<vector<int>>::const_iterator& iter)
{
	for (vector<int>::const_iterator iter1 = iter->begin();
		iter1 != iter->end();
		iter1++) {
		cout << *iter1 << " ";
	}
	cout << endl;
}

void SpeechManager::RoundRecorderPrinter(const vector<vector<int>>& v) const
{
	for (vector<vector<int>>::const_iterator iter1 = v.begin();
		iter1 != v.end(); iter1++) {
		for (vector<int>::const_iterator iter2 = iter1->begin();
			iter2 != iter1->end(); iter1++)
		{
			cout << *iter2 << " ";
		}
		cout << endl;
		cout << endl;
	}
}

void SpeechManager::ShowMenu()
{
	cout << "***************************************" << endl;
	cout << "***********��ӭ�μ��ݽ�����************" << endl;
	cout << "**********1.��ʼ�ݽ�����***************" << endl;
	cout << "**********2.�鿴�����¼***************" << endl;
	cout << "**********3.��ձ�����¼***************" << endl;
	cout << "**********0.�˳�����*******************" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
	system("pause");
	system("cls");
}

void SpeechManager::PrintSpeaker()
{
	for (map<int, Speaker>::const_iterator iter = this->GetSpeaker().begin();
		iter != this->GetSpeaker().end(); iter++) {
		cout << "������" << iter->second.GetName() << " ������" << endl;
		auto score = iter->second.GetScoreRecs();
		int round = 1;
		for (vector<double>::const_iterator iter1 = score.begin(); iter1 != score.end(); iter1++) {
			cout << "�� " << round << " �ַ���Ϊ��" << *iter1 << " "<<endl;
			round++;
		}
		cout << endl;
		cout << endl;
	}
}

//��ǩ-����-������� total_round�� Ҫѡ���ٽ����� �԰�->��ǿ->?��ʵ�Ҳ��Ǻܶ�����
//����������ļ���
void SpeechManager::StartSpeech()
{
	this->SpeechDraw();//��ǩ
	this->SpeechContest();//������ʼ
}

void SpeechManager::SpeechContest()
{
	int pos = this->index_ - 1;//Ŀǰ������,�±��0��ʼ
	
	cout << "------------------------------------" << endl;
	cout << "|-------- �� " << this->index_ << " �ֱ�����ʼ��--------|"<<endl;
	cout << "------------------------------------" << endl;

	//׼����ʱ���������С��ɼ�
	//double ������ int ѡ�ֱ�ţ��Է���Ϊkey�����Ƿ��������ظ�,����ʹ��multimap
	multimap<double,int, greater<double>>group_score;
	//���������ͱ�����������ȷ��С���ж���ѡ��,���������������
	vector<vector<int>>::const_iterator citer = this->round_recorder_.begin();
	int group_speaker_num = citer->size() / total_round_;

	//��¼��ǰ��Ա�ĸ�����
	int num= 0;
	vector<vector<int>>::iterator iter_rc = this->round_recorder_.begin();
	//��index�����ڱ�����ѡ�ֵ�������Ӧ���±�
	iter_rc += pos;

	//iterָ����ǵ�index�ֵ�ѡ�ֵļ��ϣ�
	//iter1ָ����ǵ�index�ֵ�ĳ��ѡ�֣�
	for (vector<int>::iterator iter1 =(*iter_rc).begin();
		iter1 != (*iter_rc).end();
		iter1++) {
		//��ί��ֻ���
		//��ʼ��֣���+1
		++num;
		//deque���������ڼ�¼������ί�Ĵ��
		deque<double>d;
		for (int i = 0; i < this->commentator_num_; i++)
		{
			//��������60~100
			double score = (rand() % 401 + 600) / 100.f;
			
			//cout << score << " ";//��ί���
			
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());//�Ӵ�С������

		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0);//�������

		double avg = sum / (double)d.size();//������ƽ����Ϊѡ�ֵ÷�
		
		//cout << "ƽ���֣�" << avg << endl;
		//map<int, Speaker>::iterator miter = find_if(this->speaker_.begin(), this->speaker_.end(),);

		this->speaker_[*iter1].ModiScore(index_, avg);//�޸�ĳ�ֵķ���

		//cout << "���: " << *iter1 << " ����: " <<
		//	this->speaker_[*iter1].GetName() <<" �ڵ� " << 
		//	this->index_ << " �ֵķ���Ϊ��" << 
		//	this->speaker_[*iter1].GetScoreRound(index_) << endl;

		group_score.insert(make_pair(avg, (*iter1)));//С�������¼


		//ÿX�ˣ�ȡǰy��
		//����
		if (num%group_speaker_num==0)
		{
			cout << "��" << num / group_speaker_num << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator group_score_it = group_score.begin();
				group_score_it != group_score.end();
				group_score_it++) {
				cout << "��ţ�" << group_score_it->second << " ������" << this->speaker_[group_score_it->second].GetName() << " �ɼ���" <<
					this->speaker_[group_score_it->second].GetScoreRound(this->index_)<<endl;
			}

			//ȡ��ǰ����
			int count = 0;
			//for (multimap<double, int, greater<double>>::iterator top_three_it = group_score.begin();
			//	top_three_it != group_score.end(),count!=3;
			//	top_three_it++,count++) {
			//	
			//	int pos = this->index_ - 1;

			//	vector<vector<int>>::iterator push_round_top_it = this->round_recorder_.begin();
			//	
			//	push_round_top_it +=pos;
			//	
			//	push_round_top_it->push_back(top_three_it->second);

			//}
			//
			//С��������յ�����Ȼ��׷��
			group_score.clear();
		}

	}
}

const vector<vector<int>>& SpeechManager::GetRoundRecorder() const
{
	return this->round_recorder_;
}

const map<int, Speaker>& SpeechManager::GetSpeaker() const
{
	return this->speaker_;
}

const int& SpeechManager::GetIndex() const
{
	return this->index_; 
}

const vector<int>& SpeechManager::GetRoundSpeakers(const int& round) const
{
	{
		if (round > this->round_recorder_.size())
		{
			cout << "��δ���е�" << round << "�����������޴��ּ�¼" << endl;
			return (*(this->round_recorder_.end()));//����β�������
		}
		else
		{
			int index = round - 1;
			vector<vector<int>>::const_iterator citer = this->GetRoundRecorder().begin();
			citer += index;//���ʵ�round��,���������±��0��ʼ
			return(*citer);//���ص�round�ֵ�ѡ�ֱ��
		}

	}
}

void SpeechManager::SetSpeaker(const map<int, Speaker>& sp)
{
	this->speaker_ = sp;
}

void SpeechManager::SetIndex(const int& index)
{ 
	this->index_ = index; 
}

void SpeechManager::SetRoundRecorder(const vector<vector<int>>& rec)
{
	this->round_recorder_ = rec;
};

void SpeechManager::InitSpeech(const string& name_seed, const int& total_round, const int& commentator_num)
{
	//������֤Ϊ��
	this->round_recorder_.clear();
	this->speaker_.clear();

	//��ʼ����������
	this->index_ = 1;
	this->total_round_ = total_round;
	this->commentator_num_ = commentator_num;

	//ѹ������resize��
	//����roundΪrecorder���������ռ�,�ƺ������е��˷ѣ�
	//��ά��vector����Ҫ�Լ���������һ��ά�ȣ���Ȼ������и������⣬ռ�ݵ�һ��ά�ȵ���ʲô����total_round����vector��
	this->round_recorder_.reserve(total_round);
	//����name_seedΪÿ�ַ���ռ�
	for (vector<vector<int>>::iterator iter=this->round_recorder_.begin();
		iter!=this->round_recorder_.end();
		iter++)
	{
		iter->reserve(name_seed.size());
	}
	//ΪspeakerԤ��?û���������
}

void SpeechManager::SpeechDraw()
{
	cout << "�� " << this->index_ << " �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	vector<vector<int>>::iterator iter = this->round_recorder_.begin();//��������Ŀǰָ���һ�ֵĲ�����Ա��ŵļ��ϣ�Ҳ����һ��vector

	//ʵ�֣���index�ֵĳ�ǩ
	iter += (index_ - 1);//�����±��0��ʼ
	//����˳��Ҳ���ǳ�ǩ
	random_shuffle(iter->begin(), iter->end());//����˳��

	//��ӡ
	PrintRound(iter);
	cout << "-----------------------------------" << endl;
}

