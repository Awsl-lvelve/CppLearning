#include<iostream>
using namespace std;
const double PI = 3.14;

//��װ
//�����Ժ���Ϊ��������
//�����Ժ���Ϊ����Ȩ�޿���


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