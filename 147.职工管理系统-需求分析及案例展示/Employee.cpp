#include"Employee.h"

Employee::Employee(int id, std::string name, int dId) {
	this->SetDeptId(dId);
	this->SetId(id);
	this->SetName( name);
}

std::string Employee::getDeptName() const
{
	return std::string("雇员");
}

void Employee::showInfo()const {
	std::cout << "职工编号：" << this->getId() << '\t';
	std::cout << "职工姓名：" << this->getName() << '\t';
	std::cout << "职工部门：" << this->getDeptName() << '\t';
	std::cout << "岗位职责：完成经理指派的任务" << std::endl;
}

