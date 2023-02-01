#include<iostream>
using namespace std;

//两大问题
//🐏继承动物的数据，🐫继承了动物的数据，羊驼使用数据会产生二义性
//羊驼继承动物的数据继承了两份，但是我们仅仅需要一份即可

//解决办法：
//利用虚继承的方式解决菱形继承的问题


class Animal {
public:
	int life_length;
};

//虚继承
class Sheep:virtual public Animal {

};

//虚继承
class Camel:virtual public Animal {

};

class Cnm:public Sheep,public Camel {

};

void test01() {
	Cnm cnm;
	//cnm.life_length = 18;//不明确
	cnm.Sheep::life_length = 19;
	cnm.Camel::life_length = 28;

	//我们实际知道，仅仅需要一份年龄数据就可以了
	//如果进行了虚继承，那么lifeLength就是一份数据了

	cout << "Inherit From Sheep: " << cnm.Sheep::life_length << endl;
	cout << "Inherit From Camel: " << cnm.Camel::life_length << endl;
	cout << cnm.life_length << endl;

	

}

//vbptr virtual base pointer
//虚基类指针：指向一个叫vb table(virtual base table 虚基类表)
//

int main() {
	test01();
}

