#include<iostream>
#include<string>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& out, const Person& p);
public:
	Person() {
		this->_name = new string("DefaultName");
		this->_age = -1;
	}//Ĭ�Ϲ���

	Person(int age, string name) {
		this->_name = new string(name);
		this->_age = age;

		//cout << "�вι��캯������" << endl;
	};//�вι���

	Person(const Person& person) {
		this->_name = person._name;
		this->_age = person._age;
	}

	~Person() {
		if (this->_name!=NULL)
		{
			delete this->_name;
			this->_name = NULL;
		}
		//cout << "������������" << endl;
	};//����

	//Person(const Person& person) {
	//	this->_age =person._age;
	//	this->_name = new string(*person._name);//���¿��ٿռ䣬��������ʱ�ڴ��ظ��ͷ�

	//	//�����Ƿ���ÿ������캯��
	//	//cout << "�������캯������" << endl;

	//}//�������죬��
	
	Person& operator+(const Person& p) {
		this->_age += p._age;
		return *this;
	}//+�����������

	Person& operator-(const Person& p) {
		this->_age -= p._age;
		return *this;
	}//�������������

	Person& operator++() {
		++this->_age;
		return *this;
	}//ǰ�õ���

	Person operator++(int) {

		//���õ������ص���ֵ�����ܷ��ؾֲ�����������
		//Person temp = * this;
		//�����Ǵ���ģ���û��Ϊtemp��name���ٿռ䣬�ᵼ�´���

		Person temp(this->_age, *this->_name);

		++this->_age;
		return temp;
	}//���õ���

	//�������һ�����⣬Ϊ�˽����ǳ�������������������Ĺ��캯��
	//����ͨ�ĸ�ֵ����
	//Ҳ���ܽ������ñ������ṩ��Ĭ�ϵĿ������캯�����ض���ĸ�ֵ�����
	//������ǳ����������
	Person& operator=(Person& p) {
		//���ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (this->_name!=NULL)
		{
			delete this->_name;
			this->_name = NULL;
		}

		this->_name = new string(*p._name);

		this->_age =p._age;

		return *this;
	}

	//get����
	int GetAge()const {
		return this->_age;
	}

	string GetName()const {
		return *this->_name;
	}

	//set����
	void SetAge(int age) {
		this->_age = age;
	}

	void SetName(string name) {
		this->_name = new string(name);
	}
private:
	int _age;
	string* _name;
};

//�������������
ostream& operator<<(ostream&out,const Person& p) {
	out << "���䣺" << p._age << " " << "������" << *p._name;
	return out;
}

//���캯������-Ĭ��
void test01() {
	Person p1;
	p1.SetAge(18);
	p1.SetName("Ultraman");

	//��ӡ
	cout << p1 << endl;	
}

//���캯������-�в�
void test02() {
	Person p1(18,"Nexus");
	cout << p1 << endl;
}

//�����������-����
void test03() {
	Person p1(18, "Nexus");
	Person p2(p1);
}

//ǰ�õ������������
void test04() {
	Person p1(18, "Nexus");
	cout << p1 << endl;
	++p1;
	cout << p1 << endl;
	cout << ++(++p1) << endl;
}

//���õ������������
void test05() {
	Person p1(18, "Nexus");
	cout << p1 << endl;
	cout << p1++ << endl;
	cout << p1 << endl;
	cout << (p1++)++ << endl;
}

//int�ĵ���
void testInt() {
	int a = 1;
	cout << ++a << endl;
	int b = 2;
	cout << b++ << endl;
	cout << b << endl;
}

//��ֵ��������ز���
void test06() {
	Person p1;
	cout << p1<<endl;

	Person p2=p1;
	//Person p2(p1);

	cout << p2 << endl;
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();

	//testInt();
	test06();

}
