#include"Boss.h"

Boss::Boss(int id, std::string name, int dId) {
	this->SetId(id);
	this->SetName(name);
	this->SetDeptId(dId);
}

void Boss::showInfo() const
{
	std::cout << "ְ����ţ�" << this->getId() << '\t';
	std::cout << "ְ��������" << this->getName() << '\t';
	std::cout << "ְ�����ţ�" << this->getDeptName() << '\t';
	std::cout << "��λְ��ָ������" << std::endl;

}

std::string Boss::getDeptName() const
{
	return std::string("�ϰ�");
}
