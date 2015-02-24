#pragma once
#include "FeedingBehavior.h"
#include "Morg.h"

class Envelop :
	public FeedingBehavior
{
public:
	Envelop(void);
	~Envelop(void);
	void consume(MorgMortality *morgMortality, void* prey);
	std::string toString();
};

