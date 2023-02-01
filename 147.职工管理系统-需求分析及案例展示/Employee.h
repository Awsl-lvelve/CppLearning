#pragma once
#include"Worker.h"

class Employee :public Worker 
{
public:
	Employee()=default;

	Employee(int id, std::string name, int dId);
	
	virtual void showInfo() const;

	virtual std::string getDeptName() const;

};