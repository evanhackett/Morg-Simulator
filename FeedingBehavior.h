#pragma once
#include "MorgMortality.h"
#include <string>

class FeedingBehavior
{
public:
	virtual void consume(MorgMortality *morgMortality, void* prey) = 0;
	virtual std::string toString() = 0;
};

