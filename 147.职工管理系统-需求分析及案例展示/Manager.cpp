#include"Manager.h"

Manager::Manager(int id, std::string name, int dId) {
	this->SetId(id);
	this->SetName(name);
	this->SetDeptId(dId);
}

void Manager::showInfo() const
{
	std::cout << "职工编号：" << this->getId() << '\t';
	std::cout << "职工姓名：" << this->getName() << '\t';
	std::cout << "职工部门：" << this->getDeptName() << '\t';
	std::cout << "岗位职责：完成Boss指派的任务" << std::endl;

}

std::string Manager::getDeptName() const
{
	return std::string("经理");
}
