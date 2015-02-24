#pragma once
#include "movebehavior.h"
class Paddle :
	public MoveBehavior
{
public:
	Paddle(void);
	~Paddle(void);
	Location* move(Location *currentLocation, Direction *direction);
	std::string toString();
};

