#include "stdafx.h"
#include "Morg.h"
#include <iostream>


Morg::Morg() :
	alive(true),
	age(0),
	type('z'),
	location(nullptr),
	destination(nullptr),
	direction(new Direction(1,0)),
	movement(nullptr),
	feedBehavior(nullptr),
	reproduction(nullptr),
	subject(nullptr),
	able_to_birth(false)
{
}


Morg::~Morg(void)
{
	if (location) {
		delete location;
	}
	if (direction) {
		delete direction;
	}
	if (movement) {
		delete movement;
	}
}

void Morg::printType() const
{
	std::cout << type;
}


bool Morg::isAlive() const 
{
	return alive;
}
	
void Morg::setDead()
{
    alive = false;
    location = nullptr;
}

Location* Morg::getLocation() const
{
    return location;
}
    
Direction* Morg::getDirection() const
{
    return direction;
}

Location* Morg::getDestination() const
{
	return destination;
}

Morg* Morg::getSubject() const
{
	return subject;
}

char Morg::getType() const
{
	return type;
}

int Morg::getAge() const
{
	return age;
}

std::string Morg::getMoveBehaviorString() const
{
	return movement->toString();
}

std::string Morg::getFeedBehaviorString() const
{
	return feedBehavior->toString();
}

std::string Morg::getReproductionBehaviorString() const
{
	return reproduction->toString();
}

std::vector<char> Morg::getFeedList() const
{
	return feedList;
}


void Morg::incrementAge()
{
	age++;
}

void Morg::setType(char morgType)
{
	type = morgType;
}

void Morg::setSubject(Morg* newSubject)
{
	subject = newSubject;
	if (subject) {
		this->printType();
		std::cout << "Morg " << this << " is now following ";
		newSubject->printType();
		std::cout << "Morg " << newSubject << std::endl;
		newSubject->registerObserver(this);
		setDestination(subject->getLocation());
	}
}

void Morg::setLocation(Location *newLocation)
{
    location = newLocation;
}
    
void Morg::setDirection(Direction *newDirection)
{
	direction = newDirection;
}

void Morg::setDestination(Location *newDestination)
{
	destination = newDestination;
}

void Morg::setMoveBehavior(MoveBehavior *newBehavior)
{
	movement = newBehavior;
}

void Morg::setFeedingBehavior(FeedingBehavior *newBehavior)
{
	feedBehavior = newBehavior;
}

void Morg::setReproductionBehavior(ReproductionBehavior *newBehavior)
{
	reproduction = newBehavior;
}

void Morg::setFeedList(std::vector<char> feedList)
{
	this->feedList = feedList;
}


Direction* Morg::destinationDirection() const
{
	int x = 0;
	int y = 0;

	if (destination->getX() > location->getX()) {
		x = 1;
	} 
	else if (destination->getX() < location->getX()) {
		x = -1;
	}

	if (destination->getY() > location->getY()) {
		y = 1;
	} 
	else if (destination->getY() < location->getY()) {
		y = -1;
	}

	Direction *newDirection = new Direction(x, y);

	return newDirection;
}


void Morg::registerObserver(Observer *observer)
{
	list.push_back(observer);

}


void Morg::removeObserver(Observer *observer)
{
	observer->Update(nullptr);
	list.remove(observer);
}

void Morg::removeAllObservers()
{
	Observer *obs;
	std::list<Observer*>::iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++)
	{
		obs = *iter;
		obs->Update(nullptr);
	}

	list.clear();
}


void Morg::notifyObservers(Location *location)
{
	Observer *obs;
	std::list<Observer*>::iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++)
	{
		obs = *iter;
		obs->Update(location);
	}
}

void Morg::Update(Location *location)
{
	if (location) {
		setDestination(location);
	}	
	else {
		setDestination(getLocation());
		setSubject(nullptr);
	}

}

void Morg::act(MorgMortality *morgMortality)
{
	if ((getAge()+1) % 5 == 0) {
		able_to_birth = true;
	}


	Direction* newDirection = destinationDirection();
	setDirection(newDirection);

	this->printType();
	std::cout << "Morg " << this << " ";

	setLocation(movement->move(getLocation(), getDirection()));

	
	bool aliveSubject = false;
	if (getSubject()) {
		if (getSubject()->isAlive())
			aliveSubject = true;
	}

	// if destination == current location, and this morg has a living subject, call consume
	if (aliveSubject) {
		if (getDestination()->getX() == getLocation()->getX() && getDestination()->getY() == getLocation()->getY()) {
			feedBehavior->consume(morgMortality, getSubject());
		}
	}

	
	if (able_to_birth) {
		reproduction->reproduce(morgMortality, this->getType(), this->getLocation(), this->getMoveBehaviorString(), 
			this->getFeedBehaviorString(), this->getFeedList(), this->getReproductionBehaviorString());
		able_to_birth = false;
	}
	

	notifyObservers(getLocation());

	incrementAge();
}