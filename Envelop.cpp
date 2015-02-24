#include "stdafx.h"
#include "Envelop.h"
#include <iostream>


Envelop::Envelop(void)
{
}


Envelop::~Envelop(void)
{
}

void Envelop::consume(MorgMortality *morgMortality, void* prey)
{
	std::cout << "Enveloping..." << std::endl;
	morgMortality->kill(prey);
}

std::string Envelop::toString()
{
	return "Envelop";
}