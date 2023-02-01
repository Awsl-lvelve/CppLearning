#include<iostream>
#include<string>

class Cannon;
class Tank;


class Pos {
public:
	friend class Cannon;
	friend class Tank;
	Pos() = default;
	Pos(double x, double y, double z) {
		this->_x = x;
		this->_y = y;
		this->_z=z;
	}

	Pos& operator=(const Pos& pos) {
		this->_x = pos._x;
		this->_y = pos._y;
		this->_z = pos._z;
	}

	bool operator==(const Pos& pos) {
		if (this->_x==pos._x&&
			this->_y==pos._y&&
			this->_z==pos._z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	double _x;
	double _y;
	double _z;
};



class Tank
{
public:
	friend class Cannon;
	Tank() = default;
	Tank(Pos pos, int cannon_counter, bool load, double direction) {
		this->_tank_pos = pos;
		this->_cannon_counter = cannon_counter;
		this->_loaded_or_not = true;
		this->_direction = direction;
		this->_canon._canno_pos = this->_tank_pos;
	};


	void FireUp(Tank target) {
		if (this->_loaded_or_not == true)
		{
			if (this->_canon.CheckHitOrNot(target))
			{
				this->_canon.Boom();
			}

			this->_loaded_or_not = false;
		}
	}

	void Reload() {
		if (this->_loaded_or_not == false)
		{
			this->_cannon_counter--;
			this->_loaded_or_not = true;
			std::cout << "loaded" << std::endl;
		}
		else
		{
			return;
		}
	}

	void Move(Pos p) {
		this->_tank_pos = p;
	}

	Pos GetPos() {
		return this->_tank_pos;
	}

	void SetPos(Pos p) {
		this->_tank_pos = p;
	}

	void Init() {
		this->_tank_pos = Pos(1, 1, 1);
		this->_loaded_or_not = true;
		this->_direction = 0;
		this->_cannon_counter = 10;
		this->_canon = Cannon(this->_tank_pos);
	}
	void Init1() {
		this->_tank_pos = Pos(1, 1, 2);
		this->_loaded_or_not = true;
		this->_direction = 0;
		this->_cannon_counter = 10;
		this->_canon = Cannon(this->_tank_pos);
	}
private:
	Pos _tank_pos;
	int _cannon_counter;
	bool _loaded_or_not;
	double _direction;
	Cannon _canon;

};

class Cannon {
	
public:
	friend class Tank;
	Cannon() = default;
	Cannon(Pos p) {
		this->_canno_pos = p;
	}

	void Boom() {
		std::cout << "±¬Õ¨" << std::endl;
	}
	bool CheckHitOrNot(Tank tank) {
		if (this->_canno_pos==tank._tank_pos)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	Pos _canno_pos;
};



int main() {
	Tank t1;
	t1.Init();

	Tank t2;
	t2.Init1();

	t2.FireUp(t1);


}



