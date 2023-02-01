#include"GoodGuy.h"
#include<iostream>

GoodGuy::GoodGuy() {
	building = new Building;
}
void GoodGuy::Visit() {
	std::cout << this->building->_sitting_room << std::endl;
	std::cout << this->building->_bed_room << std::endl;
}
