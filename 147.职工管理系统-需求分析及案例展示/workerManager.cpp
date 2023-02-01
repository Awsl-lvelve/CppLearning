#include "workerManager.h"

wokerManager::wokerManager()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	//文件不存在的情况
	if (!ifs.is_open())
	{
		std::cout << "文件不存在!" << std::endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "文件为空!" << std::endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	int num = this->getEmpNum();
	std::cout << "职工个数：" << num << std::endl;
	this->m_EmpNum = num;//更新成员属性

	this->m_FileIsEmpty = false;//更新标识符

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化
	this->InitEmp();

	//打印输出
	for (size_t i = 0; i < m_EmpNum; i++)
	{
		std::cout << "职工编号：" << this->m_EmpArray[i]->getId() << '\t'
			<< "姓名：" << this->m_EmpArray[i]->getName() << '\t'
			<< "部门编号：" << this->m_EmpArray[i]->getDeptId() << std::endl;
	}
}

wokerManager::~wokerManager()
{
	if (this->m_EmpArray!=NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//展示菜单
void wokerManager::showMenu()
{
	std::cout << "***********************************" << std::endl;
	std::cout << "**********0.退出管理程序**********" << std::endl;
	std::cout << "**********1.增加职工信息**********" << std::endl;
	std::cout << "**********2.显示职工信息**********" << std::endl;
	std::cout << "**********3.删除离职职工**********" << std::endl;
	std::cout << "**********4.修改职工信息**********" << std::endl;
	std::cout << "**********5.查找职工信息**********" << std::endl;
	std::cout << "**********6.按照编号排序**********" << std::endl;
	std::cout << "**********7.清空所有文档**********" << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
	std::cout << "请输入你的选择" << std::endl;
}

//退出系统
void wokerManager::exitSystem()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}

//添加职工
void wokerManager::addEmp()
{
	std::cout << "请输入添加职工数量:  " << std::endl;
	int addNum = 0;//保存职工数量
	std::cin >> addNum;

	if (addNum > 0) {
		//添加
		//计算新空间大小
		int newSize = this->getEmpNum() + addNum;
		//设置开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间的内容转移至新空间,如果原空间有内容的话
		if (this->m_EmpArray!=NULL)
		{
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量输入新数据
		for (size_t i = 0; i < addNum; i++)
		{
			int id;//职工编号
			std::string name;//职工姓名
			int dSelect;//部门选择

			std::cout << "请输入第" << i + 1 << "位新职工的编号" << std::endl;
			std::cin >> id;

			std::cout << "请输入第" << i + 1 << "位新职工的姓名" << std::endl;
			std::cin >> name;

			std::cout << "请输入第" << i + 1 << "位新职工的岗位" << std::endl;
			std::cout << "1.普通职工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
			std::cin >> dSelect;

			Worker* woker = NULL;

			switch (dSelect)
			{
			case 1:
				woker = new Employee(id, name, 1);
				break;
			case 2:
				woker = new Manager(id, name, 2);
				break;
			case 3:
				woker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工保存在newspace中
			newSpace[this->m_EmpNum + i] = woker;
		}
		//释放原空间
		delete[] this->m_EmpArray;

		//更新空间指向
		this->setEmpArray(newSpace);

		//更新人数
		this->setEmpNum(newSize)  ;

		//更新文件是否为空的标志
		this->setFileIsEmpty(false);
		//保存
		this->save();
		std::cout << "已经添加" << addNum << "位职工" << std::endl;
	}
	else
	{
		std::cout << "输入有误" << std::endl;
	}

	//按任意键清屏后返回上级目录
	system("pause");
	system("cls");
}

void wokerManager::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);//用输出的方式打开文件
	//将每个人数据写入文件中
	for (size_t i = 0; i < this->getEmpNum(); i++)
	{
		ofs << this->m_EmpArray[i]->getId() << '\t'
			<< this->m_EmpArray[i]->getName() << "\t"
			<< this->m_EmpArray[i]->getDeptId() << std::endl;

		std::cout << this->m_EmpArray[i]->getId() << '\t'
			<< this->m_EmpArray[i]->getName() << "\t"
			<< this->m_EmpArray[i]->getDeptId() << std::endl;

	}

	ofs.close();
}

int wokerManager::getEmpNum()
{
	std::ifstream ifs;

	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int num = 0;

	while ((ifs>>num&&ifs>>name&&ifs>>dId)&&!ifs.eof())
	{
		++num;
	}

	ifs.close();

	return num;
}

void wokerManager::InitEmp()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int index = 0;

	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		Worker* woker = NULL;
		//根据不同部门创建不同职工
		if (dId==1)
		{
			woker = new Employee(id, name, dId);
		}
		else if (dId==2)
		{
			woker = new Manager(id, name, dId);
		}
		else if (dId==3)
		{
			woker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = woker;
		index++;
	}
	ifs.close();

}

int wokerManager::CheckIsExist(const std::string& empName) const {
	int index = -1;
	for (size_t i = 0; i < this->getEmpNum(); i++)
	{
		if (this->m_EmpArray[i]->getName()==empName) {
			index = i;
			return index;
		}
	}
	return -1;
}

int wokerManager::CheckIsExist(const int& empId) const
{
	int index = -1;
	for (size_t i = 0; i < this->getEmpNum(); i++)
	{
		if (this->m_EmpArray[i]->getId() == empId) {
			
			index = i;
			return index;
		}
	}
	return -1;
}

//get方法
int wokerManager::getEmpNum() const
{
	return this->m_EmpNum;
}

//set方法
void wokerManager::setEmpNum(const int &size)
{
	this->m_EmpNum = size;
}

Worker** wokerManager::getEmpArray() const
{
	if (this->m_EmpArray!=NULL)
	{
		return this->m_EmpArray;
	}
	else
	{
		return nullptr;
	}
}

void wokerManager::setEmpArray(Worker** empArray)
{
	this->m_EmpArray = empArray;
}

bool wokerManager::getFileIsEmpty() const
{
	return this->m_FileIsEmpty;
}

void wokerManager::setFileIsEmpty(const bool& flag)
{
	this->m_FileIsEmpty = flag;
}

void wokerManager::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "不存在职工信息" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < this->getEmpNum(); i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
		std::cout << "总人数：" << this->getEmpNum() << std::endl;
	}
}

void wokerManager::delEntrance()
{
	std::cout << "请输入删除方式" << std::endl;
	std::cout << "1.通过姓名删除" << std::endl;
	std::cout << "2.通过ID删除" << std::endl;
	int select = -1;
	std::cin >> select;

	if (select == 1)//通过姓名删除
	{
		std::cout << "请输入姓名" << std::endl;
		std::string name;
		std::cin >> name;

		int ret = this->CheckIsExist(name);//检测是否存在

		if (ret == -1)
		{
			std::cout << "不存在" << std::endl;
		}
		else
		{
			this->delEmp(ret);
		}

	}
	else if (select == 2)//通过ID删除
	{
		std::cout << "请输入ID" << std::endl;
		int id;
		std::cin >> id;
		int ret = this->CheckIsExist(id);//检测是否存在

		if (ret == -1)
		{
			std::cout << "不存在" << std::endl;
		}
		else
		{
			this->delEmp(ret);
		}
	}
}

void wokerManager::delEmp(const int& index)
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在或者记录为空" << std::endl;
	}
	else
	{
		//通过覆盖的方式删除
		//m_EmpNum-1 数组最后一个位置
		for (size_t i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}

		this->m_EmpNum--;//数量减少1
		std::cout << this->m_EmpNum<<std::endl;

		if (this->m_EmpNum == 0)//检测是否为空
		{
			this->m_FileIsEmpty = true;
			std::cout << "Here" << std::endl;
		}

		this->save();//同步保存至文件

		std::cout << "删除成功" << std::endl;
	}

}




