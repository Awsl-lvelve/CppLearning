#include<iostream>
using namespace std;

//ȫ�ֺ�����Ϊ��Ԫ
//����Ϊ��Ԫ
//��Ա������Ϊ��Ԫ

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
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�" << building._sitting_room << endl;
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�" << building._bed_room << endl;
}

void test1() {
	Building build("����","����");
	GoodGuy(build);
}

int main() {
	test1();
}

