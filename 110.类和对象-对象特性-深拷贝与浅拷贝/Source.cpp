//ǳ�������������ṩ�ļ򵥸�ֵ������һ���ȺŶ���
//������ڶ�����������һ��ռ䣬���п�����ֵ����
#include <iostream>
using namespace std;

class person
{
public:
	person();
	person(int age, int height);
	person(const person& p);
	~person();
public:
	int m_age;
	int* m_height;//��ָ���������߿��ٵ�������
};

person::person()
{
	cout << "person��Ĭ�Ϲ��캯�����ã�" << endl;
}


//������������µĿ������캯��������ʹ��ǳ����������ʹ��Ĭ�ϵĿ������캯�������ᵼ���ظ��ͷ��ڴ�����⡣
//����취�ǣ������ڶ��������ڴ棬ʹ��P1��p2��height���ڲ�ͬ��ַ���У�
//�Լ���һ���������캯��
person::person(const person& p)
{
	cout << "person�������캯������" << endl;
	//m_height=p.m_height//����������ô���Ŀ������캯����s��ǳ�������ǵ�������ĸ�Դ
	//����취����
	//�������ṩ�Ŀ������캯��
	/*m_height = p.m_height;
	m_age = p.m_age;
	*/

	//�������
	m_height = new int(*p.m_height);// �����½���һ���ռ䣬����ռ���˺�P1.height��ͬ��ֵ(*p.m_height),���������µĵ�ַ��
	m_age = p.m_age;
}

person::person(int age, int height)
{
	m_height = new int(height);//����һ��int *����m_height����
	m_age = age;
	cout << "person���вι��캯����" << endl;
}

person::~person()//�������룬���ѿ����������ͷŲ���
{
	if (this->m_height != NULL)
	{
		delete  m_height;//��������������ǵ����ظ��ͷţ��ᱨ��
		//����취:��P1 p2ָ��ͬ���ڴ棬����ָ��ֵ��һ����
		m_height = NULL;//��ֹҰָ����֣������ÿ�
	}
	cout << "person�������������ã�" << endl;
}

void test01()
{
	person p1(18, 1600);
	cout << "p1������Ϊ" << p1.m_age <<" " << "���Ϊ" << *p1.m_height << endl;
	cout << "p1�ĵ�ַ" << (int)&p1 << endl;

	person p2(p1);
	cout << "p2�ĵ�ַ" << (int)&p2 << endl;
	cout << "p2������Ϊ" << p2.m_age << " " << "���Ϊ" << *p2.m_height << endl;
}

int main()
{
	test01();
}