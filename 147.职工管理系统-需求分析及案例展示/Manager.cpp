#include"Manager.h"

Manager::Manager(int id, std::string name, int dId) {
	this->SetId(id);
	this->SetName(name);
	this->SetDeptId(dId);
}

void Manager::showInfo() const
{
	std::cout << "ְ����ţ�" << this->getId() << '\t';
	std::cout << "ְ��������" << this->getName() << '\t';
	std::cout << "ְ�����ţ�" << this->getDeptName() << '\t';
	std::cout << "��λְ�����Bossָ�ɵ�����" << std::endl;

}

std::string Manager::getDeptName() const
{
	return std::string("����");
}
