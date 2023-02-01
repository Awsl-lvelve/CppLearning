#include"Boss.h"

Boss::Boss(int id, std::string name, int dId) {
	this->SetId(id);
	this->SetName(name);
	this->SetDeptId(dId);
}

void Boss::showInfo() const
{
	std::cout << "职工编号：" << this->getId() << '\t';
	std::cout << "职工姓名：" << this->getName() << '\t';
	std::cout << "职工部门：" << this->getDeptName() << '\t';
	std::cout << "岗位职责：指派任务" << std::endl;

}

std::string Boss::getDeptName() const
{
	return std::string("老板");
}
