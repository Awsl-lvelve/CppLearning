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
		//��������չ�µĹ��ܣ������޸�Դ��
		//�����ʵ������ �ᳫ ����ԭ��
		//����ԭ�򣺶���չ���п��������޸Ľ��йر�
	}

public:
	int m_num1;
	int m_num2;

};

void test01() {
	Calculator c1(10,10);
}

//���ö�̬ʵ�ּ�����
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
	//��̬ʹ������
	//����ָ��ָ���������
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
	//ʹ�ö�̬��ʹ�ô�����������
	//1.����ʹ�ô������֯�ṹ��������
	//2.�ɶ���ǿ
	//3.����ǰ�ں��ڵ���չ��ά���Ը�

}

int main() {
	test2();
}

