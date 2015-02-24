#pragma once
class Location
{
public:
	Location(int x, int y);
	~Location(void);
	int getX() const;
	int getY() const;
	double distance(Location *location) const;

private:
	int x;
	int y;
};

