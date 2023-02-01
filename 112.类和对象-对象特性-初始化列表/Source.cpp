#include<iostream>
using namespace std;

class Phone
{
public:
	Phone() { cout << "PhoneĬ�Ϲ���" << endl; };

	Phone(string brand) :_brand(new string(brand)) { cout << "Phone�вι���" << endl; };
	
	Phone(const Phone& ph) {
		this->_brand = new string(*ph._brand);
		cout << "Phone��������" << endl;
	}

	~Phone()
	{
		if (this->_brand != NULL)
		{
			delete this->_brand;
			this->_brand = NULL;
			cout << "Phone����" << endl;
		}
	}

	string* _brand;
};

class Person
{
public:
	Person() { cout << "PersonĬ�Ϲ���" << endl; };

	Person(string name, Phone phone) :_ph(new Phone(phone)), _name(name) { cout << "Person�вι���" << endl; }
	
	Person(const Person& person) {
		this->_name = person._name;
		this->_ph = new Phone(*person._ph);
		cout << "Person��������" << endl;
	}

	~Person()
	{
		if (this->_ph!=NULL)
		{
			delete _ph;
			this->_ph = NULL;
		}
		cout << "Person����" << endl;
	}


	Phone *_ph;
	string _name;
};



void test() {
	Phone phone;
	phone._brand = new string("Samsung");
	//Phone phone1(phone);

	Person p;
	p._name = "����";
	p._ph = &phone;

	//Person p1(p);

}

int main() {
	test();
}