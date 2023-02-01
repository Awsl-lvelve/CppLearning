#pragma once
#include"Worker.h"

class Boss :public Worker
{
public:
	Boss() = default;
	Boss(int id, std::string name, int dId);

	virtual void showInfo() const;

	virtual std::string getDeptName() const;
};