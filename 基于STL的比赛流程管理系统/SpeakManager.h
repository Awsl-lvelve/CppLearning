#pragma once
#include"INCLUDES.h"
#include"Speaker.h"

class SpeakManager
{
public:

	SpeakManager();

	void ShowMenu();
	
	void ExitSystem();

	~SpeakManager();

	void StartSpeech();

	void SpeechDraw();

	void ShowRecord();

	void ClearRecord();


private:
	void InitSpeech();

	void CreateSpeaker();

	void SaveRecord();

	void LoadRecord();

	void ShowScore();

	void SpeechContest();

private:
	vector<vector<int>>m_speaker_id;
	map<int, Speaker>m_speaker_info;
	int m_index;
	bool m_file_is_empty;
	map<int, vector<string>>m_record;

};

