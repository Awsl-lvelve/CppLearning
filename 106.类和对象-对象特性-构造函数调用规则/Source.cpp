#include<iostream>
using namespace std;

//���캯�����ù���
//�û��������вι��죬��ô�������ṩ�޲ι��캯��,���ǻ��ṩ�������캯��
//����û������˿������죬��ô�������ṩ��������ͨ���캯��

class Person
{
public:
	Person();
	Person(const Person& p);
	~Person();
	Person& operator=(const Person& rhs);
	std::string _name;
};

Person::Person()
{
	cout << "�޲ι��캯��" << endl;
}

Person::~Person()
{
	cout << "��������" << endl;
}

Person& Person::operator=(const Person& rhs)
{
	// TODO: insert return statement here
	this->_name = rhs._name;
}

Person::Person(const Person& p) {
	this->_name = p._name;
	cout << "�������캯��" << endl;
}

void test() {
	Person p;
	p._name = "Hello";
	Person p2(p);

	ppkpk;
}

int main() {
	test();
}