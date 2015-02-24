#pragma once
#include "FeedingBehavior.h"
#include "Simulator.h"

class Absorb :
	public FeedingBehavior
{
public:
	Absorb(void);
	~Absorb(void);
	void consume(MorgMortality *morgMortality, void* prey);
	std::string toString();
};

