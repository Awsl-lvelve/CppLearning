#include<iostream>
using namespace std;
const double PI = 3.14;

//封装
//用属性和行为表现事物
//对属性和行为加以权限控制


class Circle
{
public:
	Circle(double r) { this->r = r; };
public:
	double GetRound() {
		return 2 * PI * this->r;
	}
	double GetSquare() {
		return PI * this->r * this->r;
	}
private:
	double r;
};



int main()
{
	Circle c(5);
	cout << c.GetSquare() << endl;
	cout << c.GetRound() << endl;
}