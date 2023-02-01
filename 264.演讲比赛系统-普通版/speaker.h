#pragma once

#include"includes.h"

class Speaker
{
public:
	Speaker();
	Speaker(const string& name);


public:
	void SetName(const string& name);
	void SetScore(const double& round_score);

	void GetName()const;
	void GetScore(const int& round);


private:
	string name_;
	double score_[2];
};

