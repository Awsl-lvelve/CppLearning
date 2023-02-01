#include<iostream>
#include<string>

using namespace std;

class AbstractDrinking {
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSometing() = 0;

	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSometing();
	}
};

class Coffee :public AbstractDrinking
{
public:
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	};
	virtual void  PourInCup() {
		cout << "���뱭��" << endl;
	};
	virtual void PutSometing() {
		cout << "�����Ǻ�ţ��" << endl;
	};
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil() {
		cout << "��ũ��ɽȪ" << endl;
	}
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	};
	virtual void  PourInCup() {
		cout << "���뱭��" << endl;
	};
	virtual void PutSometing() {
		cout << "�������" << endl;
	};
};

void doWork(AbstractDrinking *abs) {
	abs->MakeDrink();
	delete abs;//�ͷ�
}

void test() {

	//����coffee
	cout << "coffee is making��" << endl;
	doWork(new Coffee);


	//������
	cout << "Tea is making!" << endl;
	doWork(new Tea);
}

int main() {
	test();
}
