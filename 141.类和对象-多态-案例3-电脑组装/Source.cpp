#include<iostream>
#include<string>
using namespace std;

//抽象的CPU类
class Cpu
{
public:
	virtual void Calculator() = 0;
};

//抽象的显卡类
class VideoCard {
public:
	virtual void	Display() = 0;
};

//抽象的内存类
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

//显卡
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

//内存
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
		cout << "Computer构造" << endl;
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
		cout << "Computer 析构" << endl;
	}

	void working() {
		this->_cpu->Calculator();
		this->_vc->Display();
		this->_mem->Storage();
	}
};

class IntelMemory;

void test() {
	//创建第一台电脑所需配件
	Cpu* Intelcpu = new IntelCpu;

	VideoCard* Intelcard = new  IntelVideoCard;
	
	Memory* IntelMem = new IntelMemory;

	//创建第一台电脑
	Computer *c1=new Computer(Intelcpu, Intelcard, IntelMem);
	c1->working();
	delete c1;

	//创建第一台电脑所需配件
	Cpu* Lenovocpu = new LenovoCpu;

	VideoCard* Lenovocard = new LenovoVideoCard;

	Memory* lenovoMem = new LenovoMemory;
	//创建第二台电脑
	Computer *c2=new Computer(Lenovocpu, Lenovocard, lenovoMem);
	c2->working();
	delete c2;
	

}

int main() {
	test();
}