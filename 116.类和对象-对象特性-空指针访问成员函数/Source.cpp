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
		//纠正代码
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
	p->ShowAge();//对象没有实体，空的东西访问内部的具体数据，是访问不了的
}

int main() {
	Test();
}