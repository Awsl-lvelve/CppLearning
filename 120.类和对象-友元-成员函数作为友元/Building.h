#pragma once
#include<string>
#include"GoodGuy.h"

class Building
{
public:
	friend class GoodGuy;
public:
	Building();
public:
	std::string _sitting_room;
private:
	std::string _bed_room;
};

inline Building::Building() {
	this->_bed_room = "ÎÔÊÒ";
	this->_sitting_room = "¿ÍÌü";
}