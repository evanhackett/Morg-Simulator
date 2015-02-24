#pragma once

#include <string>

class Reader
{
public:
	virtual bool open() = 0;
	virtual void close() = 0;
	virtual bool readLine(std::string & buf) = 0;
};