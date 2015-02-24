#pragma once
#include "Location.h"
#include "Direction.h"
#include <string>

class MoveBehavior
{
public:
	virtual Location* move(Location *currentLocation, Direction *direction) = 0;
	virtual std::string toString() = 0;
};

