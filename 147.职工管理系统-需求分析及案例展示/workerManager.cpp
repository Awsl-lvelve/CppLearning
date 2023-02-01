#include "workerManager.h"

wokerManager::wokerManager()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		std::cout << "�ļ�������!" << std::endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "�ļ�Ϊ��!" << std::endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	int num = this->getEmpNum();
	std::cout << "ְ��������" << num << std::endl;
	this->m_EmpNum = num;//���³�Ա����

	this->m_FileIsEmpty = false;//���±�ʶ��

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��
	this->InitEmp();

	//��ӡ���
	for (size_t i = 0; i < m_EmpNum; i++)
	{
		std::cout << "ְ����ţ�" << this->m_EmpArray[i]->getId() << '\t'
			<< "������" << this->m_EmpArray[i]->getName() << '\t'
			<< "���ű�ţ�" << this->m_EmpArray[i]->getDeptId() << std::endl;
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

//չʾ�˵�
void wokerManager::showMenu()
{
	std::cout << "***********************************" << std::endl;
	std::cout << "**********0.�˳��������**********" << std::endl;
	std::cout << "**********1.����ְ����Ϣ**********" << std::endl;
	std::cout << "**********2.��ʾְ����Ϣ**********" << std::endl;
	std::cout << "**********3.ɾ����ְְ��**********" << std::endl;
	std::cout << "**********4.�޸�ְ����Ϣ**********" << std::endl;
	std::cout << "**********5.����ְ����Ϣ**********" << std::endl;
	std::cout << "**********6.���ձ������**********" << std::endl;
	std::cout << "**********7.��������ĵ�**********" << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
	std::cout << "���������ѡ��" << std::endl;
}

//�˳�ϵͳ
void wokerManager::exitSystem()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}

//���ְ��
void wokerManager::addEmp()
{
	std::cout << "���������ְ������:  " << std::endl;
	int addNum = 0;//����ְ������
	std::cin >> addNum;

	if (addNum > 0) {
		//���
		//�����¿ռ��С
		int newSize = this->getEmpNum() + addNum;
		//���ÿ����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ת�����¿ռ�,���ԭ�ռ������ݵĻ�
		if (this->m_EmpArray!=NULL)
		{
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//��������������
		for (size_t i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			std::string name;//ְ������
			int dSelect;//����ѡ��

			std::cout << "�������" << i + 1 << "λ��ְ���ı��" << std::endl;
			std::cin >> id;

			std::cout << "�������" << i + 1 << "λ��ְ��������" << std::endl;
			std::cin >> name;

			std::cout << "�������" << i + 1 << "λ��ְ���ĸ�λ" << std::endl;
			std::cout << "1.��ְͨ��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
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
			//��������ְ��������newspace��
			newSpace[this->m_EmpNum + i] = woker;
		}
		//�ͷ�ԭ�ռ�
		delete[] this->m_EmpArray;

		//���¿ռ�ָ��
		this->setEmpArray(newSpace);

		//��������
		this->setEmpNum(newSize)  ;

		//�����ļ��Ƿ�Ϊ�յı�־
		this->setFileIsEmpty(false);
		//����
		this->save();
		std::cout << "�Ѿ����" << addNum << "λְ��" << std::endl;
	}
	else
	{
		std::cout << "��������" << std::endl;
	}

	//������������󷵻��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void wokerManager::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);//������ķ�ʽ���ļ�
	//��ÿ��������д���ļ���
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
		//���ݲ�ͬ���Ŵ�����ְͬ��
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
		//�����������
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

//get����
int wokerManager::getEmpNum() const
{
	return this->m_EmpNum;
}

//set����
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
		std::cout << "������ְ����Ϣ" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < this->getEmpNum(); i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
		std::cout << "��������" << this->getEmpNum() << std::endl;
	}
}

void wokerManager::delEntrance()
{
	std::cout << "������ɾ����ʽ" << std::endl;
	std::cout << "1.ͨ������ɾ��" << std::endl;
	std::cout << "2.ͨ��IDɾ��" << std::endl;
	int select = -1;
	std::cin >> select;

	if (select == 1)//ͨ������ɾ��
	{
		std::cout << "����������" << std::endl;
		std::string name;
		std::cin >> name;

		int ret = this->CheckIsExist(name);//����Ƿ����

		if (ret == -1)
		{
			std::cout << "������" << std::endl;
		}
		else
		{
			this->delEmp(ret);
		}

	}
	else if (select == 2)//ͨ��IDɾ��
	{
		std::cout << "������ID" << std::endl;
		int id;
		std::cin >> id;
		int ret = this->CheckIsExist(id);//����Ƿ����

		if (ret == -1)
		{
			std::cout << "������" << std::endl;
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
		std::cout << "�ļ������ڻ��߼�¼Ϊ��" << std::endl;
	}
	else
	{
		//ͨ�����ǵķ�ʽɾ��
		//m_EmpNum-1 �������һ��λ��
		for (size_t i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}

		this->m_EmpNum--;//��������1
		std::cout << this->m_EmpNum<<std::endl;

		if (this->m_EmpNum == 0)//����Ƿ�Ϊ��
		{
			this->m_FileIsEmpty = true;
			std::cout << "Here" << std::endl;
		}

		this->save();//ͬ���������ļ�

		std::cout << "ɾ���ɹ�" << std::endl;
	}

}




