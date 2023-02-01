#pragma once
#include"INCLUDES.h"


class Speaker
{
public:
	
	const string& GetName()const { return this->m_name; }
	const vector<double>& GetScore()const { return this->m_score; }
	const double& GetScore(int round)const {
		vector<double>::const_iterator citer = this->m_score.begin() + (round - 1);
		return *citer;
	}
	
	void SetName(const string& name) {
		this->m_name = name;
	}

	void SetScore(const int& round, const double& score) {
		vector<double>::iterator iter= this->m_score.begin() + (round - 1);
		*iter = score;
	}

	void AppScore() {
		this->m_score.push_back(0.0);
	}

private:
	string m_name;
	vector<double>m_score;
};

