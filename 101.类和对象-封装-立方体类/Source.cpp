#include<iostream>
#include<string>

using namespace std;

class Cube
{
public:
	Cube(double a,double b,double c)
	{
		this->_a = a;
		this->_b = b;
		this->_c = c;
	}

	double GetVolume() {
		return this->_a * this->_b * this->_c;
	}

	double GetSuperficialSquare() {
		return 2 * (this->_a * this->_b + this->_a * this->_c + this->_b * this->_c);
	}

	bool CompareCube(Cube c) {
		if (this->_a==c._a&&
			this->_b==c._b&&
			this->_c==c._c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	double GetA() {
		return this->_a;
	}
	double GetB() {
		return this->_b;
	}
	double GetC() {
		return this->_c;
	}

private:
	double _a;
	double _b;
	double _c;
};

bool CubeComp(Cube c1, Cube c2) {
	if (c1.GetA()==c2.GetA()&&
		c1.GetB()==c2.GetB()&&
		c1.GetC()==c2.GetC())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	Cube c1(1, 2, 3);

	Cube c2(4, 5, 6);

	Cube c3(1, 2, 3);

	cout << c1.GetVolume() << endl;
	cout << c1.GetSuperficialSquare() << endl;

	cout << c1.CompareCube(c2) << endl;
	cout << CubeComp(c1, c3) << endl;

}