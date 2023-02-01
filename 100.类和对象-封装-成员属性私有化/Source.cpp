#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name, string id,int age) {
		this->_name = name;
		this->_id = id;
		this->_age = age;
	};

	void SetName(const string& name) {
		this->_name = name;
	}

	void SetId(const string& id) {
		this->_id = id;
	}

	void SetAge(const int age) {
		if (age > 100 || age < 18)
		{
			cout << "不合适的年龄" << endl;
			return;
		}
		else
		{
			cout << "更改成功" << endl;
			this->_age = age;
		}
	}

	string GetName() {
		return this->_name;
	}

	string GetId() {
		return this->_id;
	}

	int GetAge() {
		return this->_age;
	}


private:
	string _name;
	string _id;
	int _age;

};

int main() {
	Person p("Tom", "114514",19);

	cout<<p.GetName()<<endl;
	cout << p.GetId() << endl;

	p.SetName("苍井空");
	cout << p.GetName() << endl;
	cout << p.GetId() << endl;
	p.SetAge(38);
	p.SetAge(199);
	cout << p.GetName() << endl;
	cout << p.GetId() << endl;
	cout << p.GetAge() << endl;
}

