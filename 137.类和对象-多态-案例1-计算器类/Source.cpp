#include<iostream>
#include<string>
using namespace std;

class Calculator {
public:
	Calculator(int num1, int num2):m_num1(num1),m_num2(num2) {}

	int GetResult(string oper) {
		if (oper=="+ ")
		{
			return this->m_num1 +this-> m_num2;
		}
		else if(oper=="-")
		{
			return this->m_num1 - this->m_num2;
		}
		else if (oper=="*")
		{
			return this->m_num1 * this->m_num2;
		}
		else if (oper=="/")
		{
			return this->m_num1 / this->m_num2;
		}
		//这种想扩展新的功能，需求修改源码
		//如果真实开发中 提倡 开闭原则
		//开闭原则：对扩展进行开发，对修改进行关闭
	}

public:
	int m_num1;
	int m_num2;

};

void test01() {
	Calculator c1(10,10);
}

//利用多态实现计算器
class AbstractCalculator {
public:
	virtual int GetResult() {
		return 0;
	}

	int m_num1;
	int m_num2;
};

class AddCalculator:public AbstractCalculator {
public:
	int GetResult()
	{
		return this->m_num1 + this->m_num2;
	}
};

class SubCalculator :public AbstractCalculator {
public:
	int GetResult()
	{
		return this->m_num1 - this->m_num2;
	}
};

class MultiCalculator :public AbstractCalculator {
public:
	int GetResult()
	{
		return this->m_num1 * this->m_num2;
	}
};

void test2() {
	//多态使用条件
	//父类指针指向子类对象
	AbstractCalculator *calc = new AddCalculator;
	calc->m_num1 = 10;
	calc->m_num2 = 11;

	cout << calc->m_num1 << "+" << calc->m_num2 << "=" << calc->GetResult() << endl;
	delete calc;
	
	calc = new SubCalculator;
	calc->m_num1 = 10;
	calc->m_num2 = 11;

	cout << calc->m_num1 << "-" << calc->m_num2 << "=" << calc->GetResult() << endl;
	delete calc;

	calc = new MultiCalculator;
	calc->m_num1 = 10;
	calc->m_num2 = 11;

	cout << calc->m_num1 << "*" << calc->m_num2 << "=" << calc->GetResult() << endl;
	delete calc;
	//使用多态，使得代码量上升了
	//1.但是使得代码的组织结构更加清晰
	//2.可读性强
	//3.对于前期后期的扩展和维护性高

}

int main() {
	test2();
}

