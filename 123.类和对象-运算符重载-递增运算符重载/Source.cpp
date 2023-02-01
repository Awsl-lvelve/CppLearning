#include<iostream>

class MyInteger
{
	friend std::ostream& operator<<(std::ostream& out, MyInteger myInt);
public:
	MyInteger()=default;
	MyInteger(int num) { this->m_num = num; }
	
	//ǰ�õ���
	//����������Ϊ�˷��ر���ʹ��++(++a)�����ȷ������������õĻ�����ô���Ƕ�һ�����ݽ��в���
	MyInteger& operator++() {
		++this->m_num;
		return *this;
	}
	
	//���õ���
	//ʹ��ռλ��������Ϊǰ�úͺ��õ�����
	//ֻ����int ����������ʹ
	//ǰ�õ������ص������ã����õ������ص���ֵ
	MyInteger operator++(int) {
		//this->m_num++;
		//return *this;
		//�ȼ�¼��ǰ���
		MyInteger temp = *this;
		//�� ����
		this->m_num++;
		//����
		return temp;
	}

private:
	int m_num;
};

std::ostream& operator<<(std::ostream& out, MyInteger myInt) {
	out << "My_Int: " << myInt.m_num << std::endl;
	return out;
}

void test01() {
	MyInteger myint(10);
	std::cout << (++myint) << std::endl;

	
}

void test02() {
	MyInteger myint(10);
	std::cout << ++(++myint) << std::endl;
}

void test03() {
	MyInteger myint(10);
	std::cout << (++myint)++ << std::endl;
}

int main() {
	test01();
	test02();
	test03();
}
