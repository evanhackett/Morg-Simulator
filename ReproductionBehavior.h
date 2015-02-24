#pragma once
#include "MorgMortality.h"
#include "vector"

class ReproductionBehavior
{
public:
	virtual void reproduce(MorgMortality *morgMortality, char type, Location *location, std::string movement, 
		std::string feeding, std::vector<char> feedList, std::string reproduction) = 0;
	virtual std::string toString() = 0;
};