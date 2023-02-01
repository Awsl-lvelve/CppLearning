#pragma once
#include<string>

class Building
{
	friend class GoodGuy;
public:
	Building();
public:
	std::string _sitting_room;
private:
	std::string _bed_room;
};
