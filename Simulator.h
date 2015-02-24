#pragma once
#include <list>
#include "Morg.h"
#include "MorgMortality.h"
#include "MorgFactory.h"

class Simulator : public MorgMortality
{
public:
	Simulator(void);
	Simulator(int width, int height);
	~Simulator(void);
	void simulate(int numSteps);
	void simulateOneStep();
	Morg* nearestMorg(Morg* morg) const; // returns the nearest morg that is one of the types from the Morg's feedList.
	void kill(void* prey);
	void birth(char type, Location *location, std::string movement, std::string feeding, std::vector<char> feedList,
		std::string reproduction);
	void addMorg(Morg *morg);

private:
	int fieldWidth;
	int fieldHeight;
	const static int DEFAULT_WIDTH = 50;
	const static int DEFAULT_HEIGHT = 50;
	std::list<Morg*> morgList;
	int step;
	MorgFactory morgFactory;

};

