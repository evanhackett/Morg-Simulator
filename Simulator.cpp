#include "stdafx.h"
#include "Simulator.h"
#include <iostream>




Simulator::Simulator(void) :
	fieldWidth(DEFAULT_WIDTH),
	fieldHeight(DEFAULT_HEIGHT),
	step(0)
{
}

Simulator::Simulator(int width, int height) :
	step(0)
{
	if(width <= 0 || height <= 0) {
		std::cout << "The dimensions must be greater than zero." << std::endl
				  << "Using default values." << std::endl;
            
        fieldWidth = DEFAULT_WIDTH;
        fieldHeight = DEFAULT_HEIGHT;
	}
	else {
		fieldWidth = width;
		fieldHeight = height;
	}
}

Simulator::~Simulator(void)
{
	morgList.clear();
}

void Simulator::simulate(int numSteps)
{
	for (int i = 0; i < numSteps; i++) {
		simulateOneStep();
	}
}

void Simulator::simulateOneStep() 
{
	step++;
	std::cout << "Step: " << step << std::endl;

	// run through the list of morgs and call act() on each one, and remove dead ones
	std::list<Morg*>::iterator iter;
	for (iter = morgList.begin(); iter != morgList.end();)
	{
		Morg *morg = *iter;
		
		if(! morg->isAlive()) {
			iter = morgList.erase(iter);
		}
		else {
			if (! morg->getSubject()) {
				morg->setSubject(nearestMorg(morg));
			}

			morg->act(this);
			iter++;
		}
	}
}

void Simulator::addMorg(Morg *morg)
{
	morgList.push_back(morg);
}


Morg* Simulator::nearestMorg(Morg* morg) const
{
	Morg *morg2;
	Morg *nearest = nullptr;
	double currentMin = std::numeric_limits<double>::max();

	std::list<Morg*>::const_iterator iter;
	for (iter = morgList.begin(); iter != morgList.end();)
	{
		morg2 = *iter;
		
		std::vector<char> feedList = morg->getFeedList();
		std::vector<char>::iterator it;

		it = find(feedList.begin(), feedList.end(), morg2->getType());

		// if morg2 is in morg's feedlist and if morg2 is alive
		if (it != feedList.end() && morg2->isAlive()) {
			// calculate distance between morg and morg2
			double distance = (morg->getLocation())->distance(morg2->getLocation());

			if (distance < currentMin) {
				currentMin = distance;
				nearest = morg2;
			}
		}

		iter++;
	}
	return nearest;
}

void Simulator::kill(void* prey) {
	Morg* morgPrey = static_cast<Morg*>(prey);
	morgPrey->setDead();
	morgPrey->removeAllObservers();

	morgPrey->printType();
	std::cout << "Morg " << prey << " was consumed" << std::endl;
}

void Simulator::birth(char type, Location *location, std::string movement, std::string feeding,
					  std::vector<char> feedList, std::string reproduction) 
{
	Morg *morg = morgFactory.createMorg(type, location->getX(), location->getY(), movement, feeding, feedList,
		reproduction);

	morgList.push_back(morg);

	std::cout << type << "Morg " << morg << " was born." << std::endl;
}