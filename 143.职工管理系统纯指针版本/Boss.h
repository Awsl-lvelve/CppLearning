#pragma once
#include"Worker.h"

class Employee :public Worker
{
public:
	Employee() = default;
	Employee(std::string name, int id, int did);
	Employee(const Employee& employee);

	~Employee();
public:
	virtual void show_info() const;
	virtual int get_dept_name() const;
};