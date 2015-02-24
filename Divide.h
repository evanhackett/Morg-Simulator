#pragma once
#include "reproductionbehavior.h"
#include "Simulator.h"

class Divide :
	public ReproductionBehavior
{
public:
	Divide(void);
	~Divide(void);
	void reproduce(MorgMortality *morgMortality, char type, Location *location, std::string movement, 
		std::string feeding, std::vector<char> feedList, std::string reproduction);
	std::string toString();
};

