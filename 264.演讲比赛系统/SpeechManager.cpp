#include"SpeechManager.h"

SpeechManager::SpeechManager(const string& name_seed, const int& total_round, const int& commentator_num)
{
	//初始化容器和属性
	this->InitSpeech(name_seed,total_round,commentator_num);
	//根据种子长度创建
	this->CreateSpeaker(name_seed,total_round);

}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::CreateSpeaker(string name_seed,int total_round)
{
		
	int index_maximum = name_seed.size();//根据name_seed确定参赛选手数量
	int indexer = 0;//游标，组成参赛选手姓名的一部分

	int i = 0;
	for (i = 0; i < name_seed.size(); i++) {
		string name = string("选手") + name_seed[i];

		Speaker sp;

		sp.SetName(name);

		//根据round轮数，设置分数全为0
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
	//	string name = string("选手") + *iter;

	//	Speaker sp;

	//	sp.SetName(name);
	//	for (int i = 0; i < total_round;i++) {
	//		sp.AppScore(0.0);
	//	}//根据round轮数，设置分数全为0

	//	this->round_recorder.begin()->push_back(indexer+10001);

	//	//选手编号 以及对应的选手放入map容器中
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
	cout << "***********欢迎参加演讲比赛************" << endl;
	cout << "**********1.开始演讲比赛***************" << endl;
	cout << "**********2.查看往届记录***************" << endl;
	cout << "**********3.清空比赛记录***************" << endl;
	cout << "**********0.退出程序*******************" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
	system("pause");
	system("cls");
}

void SpeechManager::PrintSpeaker()
{
	for (map<int, Speaker>::const_iterator iter = this->GetSpeaker().begin();
		iter != this->GetSpeaker().end(); iter++) {
		cout << "姓名：" << iter->second.GetName() << " 分数：" << endl;
		auto score = iter->second.GetScoreRecs();
		int round = 1;
		for (vector<double>::const_iterator iter1 = score.begin(); iter1 != score.end(); iter1++) {
			cout << "第 " << round << " 轮分数为：" << *iter1 << " "<<endl;
			round++;
		}
		cout << endl;
		cout << endl;
	}
}

//抽签-比赛-晋级结果 total_round轮 要选多少晋级？ 对半->四强->?其实我不是很懂比赛
//保存分数到文件中
void SpeechManager::StartSpeech()
{
	this->SpeechDraw();//抽签
	this->SpeechContest();//比赛开始
}

void SpeechManager::SpeechContest()
{
	int pos = this->index_ - 1;//目前比赛轮,下表从0开始
	
	cout << "------------------------------------" << endl;
	cout << "|-------- 第 " << this->index_ << " 轮比赛开始啦--------|"<<endl;
	cout << "------------------------------------" << endl;

	//准备临时容器，存放小组成绩
	//double 分数， int 选手编号，以分数为key，但是分数可能重复,所以使用multimap
	multimap<double,int, greater<double>>group_score;
	//根据人数和比赛的总轮数确定小组有多少选手,用于满足分组需求
	vector<vector<int>>::const_iterator citer = this->round_recorder_.begin();
	int group_speaker_num = citer->size() / total_round_;

	//记录当前人员的个数，
	int num= 0;
	vector<vector<int>>::iterator iter_rc = this->round_recorder_.begin();
	//第index轮正在比赛的选手的容器对应的下标
	iter_rc += pos;

	//iter指向的是第index轮的选手的集合！
	//iter1指向的是第index轮的某个选手！
	for (vector<int>::iterator iter1 =(*iter_rc).begin();
		iter1 != (*iter_rc).end();
		iter1++) {
		//评委打分环节
		//开始打分，就+1
		++num;
		//deque容器，用于记录各个评委的打分
		deque<double>d;
		for (int i = 0; i < this->commentator_num_; i++)
		{
			//随机打分在60~100
			double score = (rand() % 401 + 600) / 100.f;
			
			//cout << score << " ";//评委打分
			
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());//从大到小的排序

		d.pop_front();//去掉最高分
		d.pop_back();//去除最低分

		double sum = accumulate(d.begin(), d.end(), 0);//分数求和

		double avg = sum / (double)d.size();//分数求平均作为选手得分
		
		//cout << "平均分：" << avg << endl;
		//map<int, Speaker>::iterator miter = find_if(this->speaker_.begin(), this->speaker_.end(),);

		this->speaker_[*iter1].ModiScore(index_, avg);//修改某轮的分数

		//cout << "编号: " << *iter1 << " 姓名: " <<
		//	this->speaker_[*iter1].GetName() <<" 在第 " << 
		//	this->index_ << " 轮的分数为：" << 
		//	this->speaker_[*iter1].GetScoreRound(index_) << endl;

		group_score.insert(make_pair(avg, (*iter1)));//小组分数记录


		//每X人，取前y人
		//按照
		if (num%group_speaker_num==0)
		{
			cout << "第" << num / group_speaker_num << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator group_score_it = group_score.begin();
				group_score_it != group_score.end();
				group_score_it++) {
				cout << "编号：" << group_score_it->second << " 姓名：" << this->speaker_[group_score_it->second].GetName() << " 成绩：" <<
					this->speaker_[group_score_it->second].GetScoreRound(this->index_)<<endl;
			}

			//取走前三名
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
			//小组容器清空掉，不然会追加
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
			cout << "并未进行第" << round << "场比赛，故无此轮记录" << endl;
			return (*(this->round_recorder_.end()));//返回尾后迭代器
		}
		else
		{
			int index = round - 1;
			vector<vector<int>>::const_iterator citer = this->GetRoundRecorder().begin();
			citer += index;//访问第round轮,但是由于下标从0开始
			return(*citer);//返回第round轮的选手编号
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
	//容器保证为空
	this->round_recorder_.clear();
	this->speaker_.clear();

	//初始化比赛轮数
	this->index_ = 1;
	this->total_round_ = total_round;
	this->commentator_num_ = commentator_num;

	//压根不用resize？
	//根据round为recorder容器保留空间,似乎这样有点浪费？
	//二维的vector，需要自己保留至少一个维度？不然会出错，有个好问题，占据第一个维度的是什么？是total_round个空vector？
	this->round_recorder_.reserve(total_round);
	//根据name_seed为每轮分配空间
	for (vector<vector<int>>::iterator iter=this->round_recorder_.begin();
		iter!=this->round_recorder_.end();
		iter++)
	{
		iter->reserve(name_seed.size());
	}
	//为speaker预留?没有这个功能
}

void SpeechManager::SpeechDraw()
{
	cout << "第 " << this->index_ << " 轮比赛选手正在抽签" << endl;
	cout << "-----------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	vector<vector<int>>::iterator iter = this->round_recorder_.begin();//迭代器，目前指向第一轮的参赛人员编号的集合，也即是一个vector

	//实现，第index轮的抽签
	iter += (index_ - 1);//经典下标从0开始
	//打乱顺序，也就是抽签
	random_shuffle(iter->begin(), iter->end());//打乱顺序

	//打印
	PrintRound(iter);
	cout << "-----------------------------------" << endl;
}

