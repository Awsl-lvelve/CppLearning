#include<iostream>
using namespace std;

//全局函数作为友元
//类作为友元
//成员函数作为友元

class Building
{
	friend void GoodGuy(const Building& building);
public:
	Building()=default;
	Building(string sittingRoom, string bedRoom) :_sitting_room(sittingRoom), _bed_room(bedRoom) {};


public:
	string _sitting_room;
private:
	string _bed_room;
};

void GoodGuy(const Building& building) {
	cout << "好基友的全局函数正在访问：" << building._sitting_room << endl;
	cout << "好基友的全局函数正在访问：" << building._bed_room << endl;
}

void test1() {
	Building build("客厅","卧室");
	GoodGuy(build);
}

int main() {
	test1();
}

