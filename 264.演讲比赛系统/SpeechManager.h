#pragma once
#include"Includes.h"
#include"Speaker.h"


class SpeechManager {
public:
	SpeechManager(const string& name_seed,const int& total_round,const int& commentator_num);
	~SpeechManager();

	//�˵�չʾ
	void ShowMenu();
	//�˳�ϵͳ
	void ExitSystem();
	//��ӡspeaker��Ԫ��
	void PrintSpeaker();
	//��ʼ����
	void StartSpeech();
	//��������
	void SpeechContest();
	//���ĳ�ֵļ�¼
	const vector<vector<int>>& GetRoundRecorder()const;
	//���speaker��Ԫ��
	const map<int, Speaker>& GetSpeaker()const;
	//���indexֵ
	const int& GetIndex()const;
	//���ĳ�ֵ�ѡ�ֵı��
	const vector<int>& GetRoundSpeakers(const int& round)const;
	//����speaker
	void SetSpeaker(const map<int, Speaker>& sp);
	//����index
	void SetIndex(const int& index);
	//����round_recordre
	void SetRoundRecorder(const vector<vector<int>>& rec);
	
private:
	//���ߺ�����
	
	//��ʼ�������캯���е���
	void InitSpeech(const string& name_seed,const int& total_round,const int&commentator_num);
	//��ǩ����StartSpeech�е���
	void SpeechDraw();
	//����������
	void CreateSpeaker(string name_seed,int total_round);
	//��ӡ ĳ �ֵĲ�����
	void PrintRound(vector<vector<int>>::const_iterator &iter);
	//��ӡ�����ֵĲ�����
	void RoundRecorderPrinter(const vector<vector<int>>& v)const;

private:
	//��¼�����Լ���Ӧ�ֵĲ���ѡ��
	vector<vector<int>>round_recorder_;
	//��� ��� �Լ� ��Ӧ�ľ���ѡ��
	map<int, Speaker>speaker_;
	//��¼��ǰ����
	int index_;
	//��¼������
	int total_round_;
	//���е�����
	int commentator_num_;
};