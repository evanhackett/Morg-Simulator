#pragma once
#include "Direction.h"
#include "Location.h"
#include "MoveBehavior.h"
#include "FeedingBehavior.h"
#include "Subject.h"
#include "Observer.h"
#include "MorgMortality.h"
#include "ReproductionBehavior.h"
#include <vector>
#include <string>

class Morg : 
	public Observer, public Subject
{
public:
	Morg();
	~Morg(void);

	void act(MorgMortality* morgMortality);
	bool isAlive() const;

	void setDead();
	void setLocation(Location *newLocation);
	void setDirection(Direction *newDirection);
	void setDestination(Location *newDestination);
	void setMoveBehavior(MoveBehavior *newBehavior);
	void setFeedingBehavior(FeedingBehavior *newBehavior);
	void setReproductionBehavior(ReproductionBehavior *newBehavior);
	void setSubject(Morg* newSubject);
	void setType(char morgType);
	void setFeedList(std::vector<char> feedList);

	Direction *destinationDirection() const;
	Morg *getSubject() const; 
	Location *getLocation() const;
	Direction *getDirection() const;
	Location *getDestination() const;
	char getType() const;
	int getAge() const;
	std::string getFeedBehaviorString() const;
	std::string getReproductionBehaviorString() const;
	std::string getMoveBehaviorString() const;
	std::vector<char> getFeedList() const;

	void incrementAge();
	void printType() const; // prints out 'A' or 'B' ... for logging purposes

	void registerObserver(Observer *observer);
	void removeObserver(Observer *observer);
	void removeAllObservers();
	void notifyObservers(Location *location);
	void Update(Location *location);

private:
	bool alive;
	bool able_to_birth;
	int age;
	char type;
	Location *location;
	Direction *direction;
	Location *destination;
	Morg *subject;   // pointer to the morg this morg is following
	MoveBehavior *movement;
	FeedingBehavior *feedBehavior;
	ReproductionBehavior *reproduction;
	std::vector<char> feedList; // list of types that this morg can consume

};

