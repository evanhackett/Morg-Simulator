#pragma once
class Direction
{
public:
	Direction(int x, int y);
	~Direction(void);
	int getX() const;
	int getY() const;

private:
	int x, y;
};

