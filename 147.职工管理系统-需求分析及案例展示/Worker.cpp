#include"Worker.h"


void Worker::SetName(const std::string& name)
{
	this->m_Name = name;
}

void Worker::SetId(const int& id)
{
	this->m_Id = id;
}

void Worker::SetDeptId(const int& deptId)
{
	this->m_DeptId = deptId;
}

int Worker::getId() const
{
	return this->m_Id;
}

std::string Worker::getName() const
{
	return this->m_Name;
}

int Worker::getDeptId() const
{
	return this->m_DeptId;
}

//std::ostream& operator<<(std::ostream& out, const Worker& woker);

