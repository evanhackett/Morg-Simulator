#include "stdafx.h"
#include "Ooze.h"
#include <iostream>


Ooze::Ooze(void)
{
}


Ooze::~Ooze(void)
{
}

Location* Ooze::move(Location *currentLocation, Direction *direction)
{
	int x;
	int y;
	bool sameX = false;
	bool sameY = false;

	if (direction->getX() < 0) {
		x = currentLocation->getX() - 1;
	}
	else if (direction->getX() == 0) {
		x = currentLocation->getX();
		sameX = true;
	}
	else {
		x = currentLocation->getX() + 1;
	}
		
	if (direction->getY() < 0) {
		y = currentLocation->getY() - 1;
	}
	else if (direction->getY() == 0) {
		y = currentLocation->getY();
		sameY = true;
	}
	else {
		y = currentLocation->getY() + 1;
	}
		
	Location *newLocation = new Location(x, y);
	if (!(sameX && sameY)) {
		std::cout << "Oozed to location (" << x << ", " << y << ")" << std::endl;
	}
	return newLocation;
}

std::string Ooze::toString()
{
	return "Ooze";
}