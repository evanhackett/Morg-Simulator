#pragma once

#include "reader.h"
#include <string>
#include <fstream>

class FileReader :
	public Reader
{
public:
	FileReader(const std::string & fileName) { this->fileName = fileName; this->isOpen = false; }
	~FileReader();

	virtual bool open();
	virtual void close();
	virtual bool readLine(std::string & buf);

private:
	std::string fileName;
	bool isOpen;
	std::ifstream inStream;
};
