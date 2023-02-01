#include<iostream>
using namespace std;

class Student
{
public:
	Student() = default;
	Student(string name, string id) { this->_name = name; this->_id = id; };


	void ShowInfo() {
		cout << "姓名: " << this->_name << endl;
		cout << "学号: " << this->_id << endl;
	}

	void SetName(string name) {
		this->_name = name;
	}

	void SetId(string id) {
		this->_id = id;
	}

private:
	string _name;
	string _id;
};

int main() {
	Student s1("张三", "10001");
	s1.ShowInfo();

	s1.SetName("VALVE");
	s1.ShowInfo();
}