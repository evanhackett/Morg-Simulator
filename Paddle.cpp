#include "stdafx.h"
#include "Paddle.h"
#include <iostream>


Paddle::Paddle(void)
{
}


Paddle::~Paddle(void)
{
}

Location* Paddle::move(Location *currentLocation, Direction *direction)
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
		std::cout << "Paddled to location (" << x << ", " << y << ")" << std::endl;
	} else {
		std::cout << "didn't move." << std::endl;
	}

	return newLocation;
}

std::string Paddle::toString()
{
	return "Paddle";
}