#include<iostream>
using namespace std;

//����Ȩ��
//public
//protected ������Է��ʸ���,�����ⲻ�ɷ���
//private ���಻�ɷ��ʸ��࣬������Ҳ�����Է���

class Person
{
public:
	string _name;
protected:
	string _car;
private:
	string _password;

public:
	Person()=default;
	Person(string name, string car, string password) {
		this->_name = name;
		this->_car = car;
		this->_password = password;
	}
};

int main() {
	Person p1("Tom","MercedesBenz","911285");

	
}

