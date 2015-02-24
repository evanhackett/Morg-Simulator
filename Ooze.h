#pragma once
#include "movebehavior.h"
class Ooze :
	public MoveBehavior
{
public:
	Ooze(void);
	~Ooze(void);
	Location* move(Location *currentLocation, Direction *direction);
	std::string toString();
};

