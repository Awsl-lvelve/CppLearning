//��������ͬ����Ա-ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա-��Ҫ���������

#include<iostream>
using namespace std;

class Base {
public:
	Base() {
		this->m_A = 100;
	}

	void Func() {
		cout << "Base Func����" << endl;
	}
	void Func(int a) {
		cout << "Base Func(int)����" << endl;
	}



	int m_A;
};

class Son :public Base {
public:
	Son() {
		this->m_A=200;
	}

	void Func() {
		cout << "Son Func����" << endl;
	}
	void Func(int a) {
		cout << "Son Func(int)����" << endl;
	}


	int m_A;
};

void test1() {
	Son s;
	cout << "Son ��m_A=" << s.m_A << endl;
	//ͬ����Ա�Ĵ���
	cout << "�̳�������m_A=" << s.Base::m_A << endl;
}

void test2() {
	Son s;
	s.Func();
	s.Base::Func();

	//�����ע�͵������е�func�������ͬ����Ա������
	//���ص�����������ͬ����Ա����
	//�����Ҫ���ʸ����б����صģ���Ҫ���������
	s.Func(100);
	s.Base::Func(100);
}

int main() {
	test1();
	test2();
}
