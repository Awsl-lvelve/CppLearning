#include<iostream>
using namespace std;

//��Ա�����ͳ�Ա�����ֿ��洢

class Person
{
public:
	Person() = default;

	~Person()
	{
	}

	//��̬��Ա����Ҳ�����ڶ���
	static void func() {
		cout << "static void func" << endl;
	}

	//�Ǿ�̬��Ա���������ڶ���
	void func1() {
		cout << "nonstatic void func" << endl;
	}

private:
	int _age;//�����һ����Ա����ô��ռ��4byte�Ŀռ�
	static int m_b;//��̬��Ա�����������ض��������Ի���4

};
int Person::m_b = 10;

void test() {
	Person p;//�ն���ռ�õ��ڴ�ռ�Ϊ��1
	//c++���������ÿ���ն������һ���ֽڵĿռ䣬��Ϊ�����ֿն���ռ���ڴ��λ��
	cout << "sizeof p = " << sizeof(p) << endl;



}

int main() {
	test();
}
