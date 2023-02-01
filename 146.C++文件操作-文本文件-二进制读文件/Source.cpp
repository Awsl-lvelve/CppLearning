#include<iostream>
#include<fstream>

using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;

};



ostream& operator<<(ostream& out, const Person& p) {
	out << p.m_Name << "\t" << p.m_Age << endl;
	return out;
}


int test() {
	ifstream ifs;

	ifs.open("./data.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "ÎÄ¼þ¶ÁÈ¡Ê§°Ü" << endl;
		return -1;
	}
	else
	{
		Person p;

		ifs.read((char*)(&p), sizeof(Person));

		cout << p;

	}

}

int main() {
	test();
}

