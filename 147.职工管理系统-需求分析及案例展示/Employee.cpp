#include"Employee.h"

Employee::Employee(int id, std::string name, int dId) {
	this->SetDeptId(dId);
	this->SetId(id);
	this->SetName( name);
}

std::string Employee::getDeptName() const
{
	return std::string("��Ա");
}

void Employee::showInfo()const {
	std::cout << "ְ����ţ�" << this->getId() << '\t';
	std::cout << "ְ��������" << this->getName() << '\t';
	std::cout << "ְ�����ţ�" << this->getDeptName() << '\t';
	std::cout << "��λְ����ɾ���ָ�ɵ�����" << std::endl;
}

