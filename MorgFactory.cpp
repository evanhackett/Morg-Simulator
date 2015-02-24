#include "stdafx.h"
#include "MorgFactory.h"
#include "Paddle.h"
#include "Ooze.h"
#include "Absorb.h"
#include "Envelop.h"
#include "Divide.h"
#include <string>


MorgFactory::MorgFactory(void)
{
}


MorgFactory::~MorgFactory(void)
{
}

Morg * MorgFactory::createMorg(char type, int x, int y, std::string movement, std::string feedBehavior,
							   std::vector<char> feedList, std::string reproduction)
{
	Morg * m = new Morg();

	m->setType(type);
	m->setLocation(new Location(x, y));
	m->setDestination(m->getLocation());
	
	if (movement == "Paddle" || movement == "Paddles")
		m->setMoveBehavior(new Paddle());
	else if (movement == "Ooze" || movement == "Oozes")
		m->setMoveBehavior(new Ooze());

	if (feedBehavior == "Absorb" || feedBehavior == "Absorbs")
		m->setFeedingBehavior(new Absorb());
	else if (feedBehavior == "Envelop" || feedBehavior == "Envelops" || feedBehavior == "Envelopes")
		m->setFeedingBehavior(new Envelop());

	if (reproduction == "Divide" || reproduction == "Divides")
		m->setReproductionBehavior(new Divide());

	m->setFeedList(feedList);

	return m;
}
