#pragma once
#include<iostream>
#include<string>

class Worker {	
public:
	Worker() = default;
	virtual~Worker() = 0;
public:
	virtual void show_info() const=0;
	virtual int get_dept_name() const=0;

	void set_name();
	void set_id();
	void set_dept_id();

	int get_dept_id();
	int get_name();
	std::string name();

private:
	std::string *m_name;
	int *m_id;
	int* m_dept_id;
};