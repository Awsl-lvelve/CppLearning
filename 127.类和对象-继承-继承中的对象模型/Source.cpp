#include<iostream>
using namespace std;

class Base
{
public :
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son :public Base
{
public:
	int m_d;
};

void test() {
	Son s;
	/// <summary>
	/// ���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	/// ����˽�г�Ա���� �Ǳ��������������ˣ����������Ƿ��ʲ����ģ�����ȷʵ���̳���ȥ��
	/// 
	/// </summary>
	cout << "sizeof son s is " << sizeof(s) << endl;
}

/// <summary>
/// ���ÿ�������������ʾ���ߣ�
/// step 1:��ת�̷�
/// step 2:��ת�ļ�·�� cd ����·��֮��
/// step 3���鿴����
/// step 4��cl reportSingleClass���� �ļ���
/// </summary>
/// <returns></returns>

int main() {
	test();
}
