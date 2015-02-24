#pragma once

#include "Morg.h"

class MorgFactory
{
public:
	MorgFactory(void);
	~MorgFactory(void);

	Morg * createMorg(char type, int x, int y, std::string movement, std::string feedBehavior,
		std::vector<char> feedList, std::string reproduction);
};

