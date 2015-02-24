#include "stdafx.h"
#include "FileReader.h"



FileReader::~FileReader()
{
	close();
}

bool FileReader::open()
{
	inStream.open(fileName);
	if (inStream.fail())
		return false;
	isOpen = true;
	return true;
}

void FileReader::close()
{
	if (isOpen)
	{
		inStream.close();
		isOpen = false;
	}
}

bool FileReader::readLine(std::string & buf)
{
	if (inStream.eof())
		return false;

	std::getline(inStream, buf);

	return true;
}
