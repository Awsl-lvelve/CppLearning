#include<iostream>
#include<string>
#include<cmath>

using namespace std;


class Point
{
public:
	Point() = default;
	Point(double x, double y) { this->_x = x; this->_y = y; };
	
	double GetX() {
		return this->_x;
	}

	double GetY() {
		return this->_y;
	}

	void SetX(double x) { this->_x = x; }
	void SetY(double y) { this->_y = y; }


private:
	double _x;
	double _y;
};

class Line
{
public:
	Line(double A, double B, double C) {
		this->_A = A;
		this->_B = B;
		this->_C = C;
	};

	double GetA() { return this->_A; }
	double GetB() { return this->_B; }
	double GetC() { return this->_C; }

	double SetA(double A) { this->_A = A; }
	double SetA(double B) { this->_B = B; }
	double SetA(double C) { this->_C = C; }

private:
	double _A;
	double _B;
	double _C;
};

double GetDistance(Point p, Line l) {
	double distance = (l.GetA() * p.GetX() + l.GetB() * p.GetY() + l.GetC())/
		pow(l.GetA()*l.GetA()+l.GetB()*l.GetB(), 0.5);
	return distance;
}

class Circle
{
public:
	Circle() = default;
	Circle(double r,double x,double y) {
		this->_r = r;
		this->_center.SetX(x);
		this->_center.SetY(y);
	};

	double GetR() { return this->_r; }
	double GetX() { return this->_center.GetX(); }
	double GetY() { return this->_center.GetY(); }

	void SetR(const double r) { this->_r = r; };
	void SetCenter(Point p) {
		this->_center = p;
	}


	void JudgeRelationship(Point p) {
		double distance = pow(
			pow(this->GetX() - p.GetX(), 2) +
			pow(this->GetY() - p.GetY(), 2), 0.5);
		cout << distance << endl;

		if (distance>this->GetR())
		{
			cout << "点在圆外" << endl;
		}
		else if (distance==this->GetR())
		{
			cout << "点在圆上" << endl;
		}
		else
		{
			cout << "点在圆内" << endl;
		}
	}

private:
	double _r;
	Point _center;
};



int main() {
	
	Point p;
	p.SetX(10);
	p.SetY(5);

	Circle c;
	Point p1(10, 0);
	c.SetR(5); c.SetCenter(p1);

	c.JudgeRelationship(p);

}



