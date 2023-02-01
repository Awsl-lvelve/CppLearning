#include "..\264.演讲比赛系统-普通版\Speaker.h"
#pragma once

#include"Includes.h"

class Speaker
{
public:

	Speaker() { this->score_recs_.reserve(10); this->name_ = "默认姓名"; }
	Speaker(const string& name, const vector<double>& score) { this->score_recs_.reserve(20); this->name_ = name; this->score_recs_ = score; }
	Speaker(const Speaker& speaker) { this->name_ = speaker.name_, this->score_recs_ = speaker.score_recs_; }
	bool operator=(const Speaker& sp) {	this->name_ = sp.name_;this->score_recs_ = sp.score_recs_;}

	//获得姓名
	void SetName(const string& name) {
		this->name_ = name;
	}

	//设置某一轮的分数
	void ModiScore(const int &round,const double &score){
		vector<double>::iterator iter = this->score_recs_.begin();
		int pos = round - 1;
		iter += pos;
		*iter = score;
	}

	//初始化某人的分数，在createSpeaker中调用，初始化值为0
	void InitScoreRecs(const double& score) { this->score_recs_.push_back(score); }
	
	//获得姓名
	const string& GetName() const{ return this->name_; }
	
	//获取某一轮选手的分数
	const double& GetScoreRound(int round){
		if ((round>=1)
			&&(round<this->score_recs_.size()))//有效的比赛轮数，其实应该是分数为非0的
		{
			int pos = round - 1;//经典下标从1开始
			vector<double>::const_iterator citer_score = this->score_recs_.begin();
			citer_score += pos;//当前轮次对应的迭代器
			return *citer_score;//返回分数
		}
		else
		{
			return -100;//无效
		}
	}

	//获得整个选手的分数的记录
	const vector<double>& GetScoreRecs()const { return this->score_recs_; }

private:
	string name_;
	vector<double> score_recs_;//记录选手在每一轮的得分
};

