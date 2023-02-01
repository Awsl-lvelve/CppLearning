#pragma once
#include"Building.h"
#include<iostream>


class GoodGuy
{
public:
	GoodGuy();
	~GoodGuy();
	void Visit();
private:
	Building* building;
}; 

GoodGuy::GoodGuy() {
	this->building = new Building;
}

void GoodGuy::Visit() {
	std::cout << this->building->_bed_room << std::endl;
	std::cout << this->building->_sitting_room << std::endl;
}

GoodGuy::~GoodGuy() {
	if (this->building!=NULL)
	{
		delete this->building;
		this->building = NULL;
	}
}