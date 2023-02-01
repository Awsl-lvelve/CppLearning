#pragma once
#include<iostream>

#include"Worker.h"
#include"Boss.h"
#include"Employee.h"
#include"Manager.h"

#include<fstream>

constexpr auto FILENAME = "emp.txt";


class wokerManager {
public:
	//构造函数
	wokerManager();

	//析构函数
	~wokerManager();

	//展示菜单
	void showMenu();

	//退出
	void exitSystem();

	//添加职工
	void addEmp();

	//展示
	void showEmp();

	//删除职工
	void delEntrance();

	//检测某员工是否存在-name
	int CheckIsExist(const std::string& empName)const;

	//检测某员工是否存在-id
	int CheckIsExist(const int& empId)const;

	//Get-Set方法
	int getEmpNum() const;

	void setEmpNum(const int& num);

	Worker** getEmpArray()const;

	void setEmpArray(Worker** empArray);

	bool getFileIsEmpty() const;

	void setFileIsEmpty(const bool& flag);

private:
	//工具函数
	//保存功能 --会不会仅仅类内函数可以调用？私有函数？
	void save();

	//获取文件中有多少员工
	int getEmpNum();

	//从文件中读取记录并初始化，WorkerManager类中的Array，
	//服务于后续的工作
	void InitEmp();

	void delEmp(const int& index);
	

private:
	Worker** m_EmpArray;
	int m_EmpNum;
	bool m_FileIsEmpty;
};
