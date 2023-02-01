#pragma once
#include"Includes.h"
#include"Speaker.h"


class SpeechManager {
public:
	SpeechManager(const string& name_seed,const int& total_round,const int& commentator_num);
	~SpeechManager();

	//菜单展示
	void ShowMenu();
	//退出系统
	void ExitSystem();
	//打印speaker中元素
	void PrintSpeaker();
	//开始比赛
	void StartSpeech();
	//比赛流程
	void SpeechContest();
	//获得某轮的记录
	const vector<vector<int>>& GetRoundRecorder()const;
	//获得speaker中元素
	const map<int, Speaker>& GetSpeaker()const;
	//获得index值
	const int& GetIndex()const;
	//获得某轮的选手的编号
	const vector<int>& GetRoundSpeakers(const int& round)const;
	//设置speaker
	void SetSpeaker(const map<int, Speaker>& sp);
	//设置index
	void SetIndex(const int& index);
	//设置round_recordre
	void SetRoundRecorder(const vector<vector<int>>& rec);
	
private:
	//工具函数集
	
	//初始化，构造函数中调用
	void InitSpeech(const string& name_seed,const int& total_round,const int&commentator_num);
	//抽签，在StartSpeech中调用
	void SpeechDraw();
	//创建参赛者
	void CreateSpeaker(string name_seed,int total_round);
	//打印 某 轮的参赛者
	void PrintRound(vector<vector<int>>::const_iterator &iter);
	//打印所有轮的参赛者
	void RoundRecorderPrinter(const vector<vector<int>>& v)const;

private:
	//记录轮数以及对应轮的参赛选手
	vector<vector<int>>round_recorder_;
	//存放 编号 以及 对应的具体选手
	map<int, Speaker>speaker_;
	//记录当前轮数
	int index_;
	//记录总轮数
	int total_round_;
	//裁判的数量
	int commentator_num_;
};