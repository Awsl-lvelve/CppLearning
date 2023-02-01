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
	//���캯��
	wokerManager();

	//��������
	~wokerManager();

	//չʾ�˵�
	void showMenu();

	//�˳�
	void exitSystem();

	//���ְ��
	void addEmp();

	//չʾ
	void showEmp();

	//ɾ��ְ��
	void delEntrance();

	//���ĳԱ���Ƿ����-name
	int CheckIsExist(const std::string& empName)const;

	//���ĳԱ���Ƿ����-id
	int CheckIsExist(const int& empId)const;

	//Get-Set����
	int getEmpNum() const;

	void setEmpNum(const int& num);

	Worker** getEmpArray()const;

	void setEmpArray(Worker** empArray);

	bool getFileIsEmpty() const;

	void setFileIsEmpty(const bool& flag);

private:
	//���ߺ���
	//���湦�� --�᲻��������ں������Ե��ã�˽�к�����
	void save();

	//��ȡ�ļ����ж���Ա��
	int getEmpNum();

	//���ļ��ж�ȡ��¼����ʼ����WorkerManager���е�Array��
	//�����ں����Ĺ���
	void InitEmp();

	void delEmp(const int& index);
	

private:
	Worker** m_EmpArray;
	int m_EmpNum;
	bool m_FileIsEmpty;
};
