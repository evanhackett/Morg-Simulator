#include "stdafx.h"
#include "Divide.h"
#include <iostream>


Divide::Divide(void)
{
}


Divide::~Divide(void)
{
}

void Divide::reproduce(MorgMortality *morgMortality, char type, Location *location, std::string movement, 
		std::string feeding, std::vector<char> feedList, std::string reproduction)
{
	morgMortality->birth(type, location, movement, feeding, feedList, reproduction);
}

std::string Divide::toString()
{
	return "Divide";
}
