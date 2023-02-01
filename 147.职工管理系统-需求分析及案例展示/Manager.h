#pragma once
#include"Worker.h"

class Manager :public Worker
{
public:
	Manager() = default;
	Manager(int id, std::string name, int dId);

	virtual void showInfo() const;

	virtual std::string getDeptName() const;
};