#include "stdafx.h"
#include "Absorb.h"
#include <iostream>



Absorb::Absorb(void)
{
}


Absorb::~Absorb(void)
{
}

void Absorb::consume(MorgMortality *morgMortality, void* prey)
{
	std::cout << "Absorbing..." << std::endl;
	morgMortality->kill(prey);
}

std::string Absorb::toString()
{
	return "Absorb";
}
