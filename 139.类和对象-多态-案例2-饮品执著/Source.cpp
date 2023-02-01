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
		cout << "煮水" << endl;
	}
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	};
	virtual void  PourInCup() {
		cout << "倒入杯中" << endl;
	};
	virtual void PutSometing() {
		cout << "加入糖和牛奶" << endl;
	};
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil() {
		cout << "煮农夫山泉" << endl;
	}
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	};
	virtual void  PourInCup() {
		cout << "倒入杯中" << endl;
	};
	virtual void PutSometing() {
		cout << "加入枸杞" << endl;
	};
};

void doWork(AbstractDrinking *abs) {
	abs->MakeDrink();
	delete abs;//释放
}

void test() {

	//制作coffee
	cout << "coffee is making！" << endl;
	doWork(new Coffee);


	//制作茶
	cout << "Tea is making!" << endl;
	doWork(new Tea);
}

int main() {
	test();
}
