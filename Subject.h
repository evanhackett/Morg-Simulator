#pragma once
#include <list>
#include "Observer.h"


class Subject
{
public:

	virtual void registerObserver(Observer *observer) = 0;
	virtual void removeObserver(Observer *observer) = 0;
	virtual void notifyObservers(Location *location) = 0;

protected:
	std::list<Observer*> list;
};

