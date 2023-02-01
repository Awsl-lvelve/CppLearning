#pragma once

#include<iostream>
#include<string>

class Worker {
	//friend std::ostream& operator<<(std::ostream& out, const Worker& woker);
public:
	//展示员工信息
	virtual void showInfo() const=0;

	virtual std::string getDeptName() const= 0;


	//Set-Get方法
	void SetName(const std::string &name);
	void SetId(const int &id);
	void SetDeptId(const int &deptId);

	int getId()const;
	std::string getName()const;
	int getDeptId()const ;

private:
	int m_Id;
	std::string m_Name;
	int m_DeptId;
};

 //std::ostream& operator<<(std::ostream& out, const Worker& woker);