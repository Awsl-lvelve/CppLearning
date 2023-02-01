#include<iostream>
#include<string>
using namespace std;

//�����CPU��
class Cpu
{
public:
	virtual void Calculator() = 0;
};

//������Կ���
class VideoCard {
public:
	virtual void	Display() = 0;
};

//������ڴ���
class Memory {
public:
	virtual void Storage() = 0;
};

//cpu
class IntelCpu :public Cpu
{
public:
	virtual void Calculator() {
		cout << "Intel cpu is working!" << endl;
	}
};

class LenovoCpu:public Cpu {
public:
	virtual void Calculator() {
		cout << "Lenovo cpu is working!" << endl;
	}
};

//�Կ�
class IntelVideoCard:public VideoCard {
public:
	virtual void Display() {
		cout << "Intel Video card is working" << endl;
	}
};

class LenovoVideoCard:public VideoCard {
public:
	virtual void Display() {
		cout << "Lenovo Video card is working" << endl;
	}
};

//�ڴ�
class IntelMemory :public Memory {
public:
	virtual void Storage() {
		cout << "Intel storage is working!" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	virtual void Storage() {
		cout << "Lenovo storage is working!" << endl;
	}
};

class Computer 
{
private:
	Cpu* _cpu;
	VideoCard* _vc;
	Memory* _mem;

public:
	Computer(Cpu* cpu, VideoCard* vc, Memory* mem)
	{
		this->_cpu = cpu;
		this->_vc = vc;
		this->_mem = mem;
		cout << "Computer����" << endl;
	}

	~Computer()
	{
		if (this->_cpu!=NULL)
		{
			delete this->_cpu;
			this->_cpu=NULL;
		}
		if (this->_vc != NULL)
		{
			delete this->_vc;
			this->_vc = NULL;
		}
		if (this->_mem!=NULL)
		{
			delete this->_mem;
			this->_mem = NULL;
		}
		cout << "Computer ����" << endl;
	}

	void working() {
		this->_cpu->Calculator();
		this->_vc->Display();
		this->_mem->Storage();
	}
};

class IntelMemory;

void test() {
	//������һ̨�����������
	Cpu* Intelcpu = new IntelCpu;

	VideoCard* Intelcard = new  IntelVideoCard;
	
	Memory* IntelMem = new IntelMemory;

	//������һ̨����
	Computer *c1=new Computer(Intelcpu, Intelcard, IntelMem);
	c1->working();
	delete c1;

	//������һ̨�����������
	Cpu* Lenovocpu = new LenovoCpu;

	VideoCard* Lenovocard = new LenovoVideoCard;

	Memory* lenovoMem = new LenovoMemory;
	//�����ڶ�̨����
	Computer *c2=new Computer(Lenovocpu, Lenovocard, lenovoMem);
	c2->working();
	delete c2;
	

}

int main() {
	test();
}