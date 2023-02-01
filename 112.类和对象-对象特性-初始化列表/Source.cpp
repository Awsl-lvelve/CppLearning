#include<iostream>
using namespace std;

class Phone
{
public:
	Phone() { cout << "Phone默认构造" << endl; };

	Phone(string brand) :_brand(new string(brand)) { cout << "Phone有参构造" << endl; };
	
	Phone(const Phone& ph) {
		this->_brand = new string(*ph._brand);
		cout << "Phone拷贝构造" << endl;
	}

	~Phone()
	{
		if (this->_brand != NULL)
		{
			delete this->_brand;
			this->_brand = NULL;
			cout << "Phone析构" << endl;
		}
	}

	string* _brand;
};

class Person
{
public:
	Person() { cout << "Person默认构造" << endl; };

	Person(string name, Phone phone) :_ph(new Phone(phone)), _name(name) { cout << "Person有参构造" << endl; }
	
	Person(const Person& person) {
		this->_name = person._name;
		this->_ph = new Phone(*person._ph);
		cout << "Person拷贝构造" << endl;
	}

	~Person()
	{
		if (this->_ph!=NULL)
		{
			delete _ph;
			this->_ph = NULL;
		}
		cout << "Person析构" << endl;
	}


	Phone *_ph;
	string _name;
};



void test() {
	Phone phone;
	phone._brand = new string("Samsung");
	//Phone phone1(phone);

	Person p;
	p._name = "张三";
	p._ph = &phone;

	//Person p1(p);

}

int main() {
	test();
}