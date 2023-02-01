#include<iostream>
using namespace std;

//访问权限
//public
//protected 子类可以访问父类,在类外不可访问
//private 子类不可访问父类，在类外也不可以访问

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

