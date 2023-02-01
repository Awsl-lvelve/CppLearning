#pragma once
#include"Building.h"

class GoodGuy
{
public:
	GoodGuy();
	void Visit();
private:
	Building* building;
};