#include "..\264.�ݽ�����ϵͳ-��ͨ��\Speaker.h"
#pragma once

#include"Includes.h"

class Speaker
{
public:

	Speaker() { this->score_recs_.reserve(10); this->name_ = "Ĭ������"; }
	Speaker(const string& name, const vector<double>& score) { this->score_recs_.reserve(20); this->name_ = name; this->score_recs_ = score; }
	Speaker(const Speaker& speaker) { this->name_ = speaker.name_, this->score_recs_ = speaker.score_recs_; }
	bool operator=(const Speaker& sp) {	this->name_ = sp.name_;this->score_recs_ = sp.score_recs_;}

	//�������
	void SetName(const string& name) {
		this->name_ = name;
	}

	//����ĳһ�ֵķ���
	void ModiScore(const int &round,const double &score){
		vector<double>::iterator iter = this->score_recs_.begin();
		int pos = round - 1;
		iter += pos;
		*iter = score;
	}

	//��ʼ��ĳ�˵ķ�������createSpeaker�е��ã���ʼ��ֵΪ0
	void InitScoreRecs(const double& score) { this->score_recs_.push_back(score); }
	
	//�������
	const string& GetName() const{ return this->name_; }
	
	//��ȡĳһ��ѡ�ֵķ���
	const double& GetScoreRound(int round){
		if ((round>=1)
			&&(round<this->score_recs_.size()))//��Ч�ı�����������ʵӦ���Ƿ���Ϊ��0��
		{
			int pos = round - 1;//�����±��1��ʼ
			vector<double>::const_iterator citer_score = this->score_recs_.begin();
			citer_score += pos;//��ǰ�ִζ�Ӧ�ĵ�����
			return *citer_score;//���ط���
		}
		else
		{
			return -100;//��Ч
		}
	}

	//�������ѡ�ֵķ����ļ�¼
	const vector<double>& GetScoreRecs()const { return this->score_recs_; }

private:
	string name_;
	vector<double> score_recs_;//��¼ѡ����ÿһ�ֵĵ÷�
};

