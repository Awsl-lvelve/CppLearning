#include<iostream>
using namespace std;


class Person
{
public:
	Person()
	{
	}

	~Person()
	{
	}

	void ShowClassName() {
		cout << "this is Person Classs" << endl;
	}
	void ShowAge() {
		//��������
		if (this==NULL)
		{
			return;
		}

		cout << this->_age << endl;
	}

private:
	int _age;
};

void Test() {
	Person* p = NULL;

	p->ShowClassName();
	p->ShowAge();//����û��ʵ�壬�յĶ��������ڲ��ľ������ݣ��Ƿ��ʲ��˵�
}

int main() {
	Test();
}