#include "stdafx.h"
#include "Location.h"
#include <cmath> 


Location::Location(int x, int y) :
	x(x),
	y(y)
{
}



Location::~Location(void)
{
}

int Location::getX() const
{
	return x;
}

int Location::getY() const
{
	return y;
}

double Location::distance(Location *location) const
{
	int x = abs(this->getX() - location->getX());
	int y = abs(this->getY() - location->getY());

	double distance = sqrt(x*x + y*y);
	return distance;
}

int abs(int x)
{
	if (x < 0) {
		x *= -1;
	}
	return x;
}
