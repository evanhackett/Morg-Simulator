#pragma once
#include <vector>
#include <string>
#include "Location.h"

class MorgMortality
{
public:
	virtual void kill(void* prey) = 0;
	virtual void birth(char type, Location *location, std::string movement, std::string feeding,
		std::vector<char> feedList, std::string reproduction) = 0;
};

