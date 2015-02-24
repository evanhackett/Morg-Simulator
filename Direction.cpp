#include "stdafx.h"
#include "Direction.h"


Direction::Direction(int x, int y) :
	x(x),
	y(y)
{
}


Direction::~Direction(void)
{
}

int Direction::getX() const
{
	return x;
}

int Direction::getY() const
{
	return y;
}