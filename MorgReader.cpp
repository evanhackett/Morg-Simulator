#include "stdafx.h"
#include "MorgReader.h"
#include <vector>
#include <string>
#include <sstream>


MorgReader::MorgReader(MorgFactory * factory, Reader * reader) :
	ReaderDecorator(reader)
{
	this->factory = factory;
}


MorgReader::~MorgReader()
{
}

std::vector<std::string> tokenize(const std::string & buf, char delim)
{
	std::vector<std::string> tokens;
	std::stringstream ss(buf);
	std::string tok;

	while (!ss.eof())
	{
		std::getline(ss, tok, delim);
		tokens.push_back(tok);
	}
	
	return tokens;
}

Morg * MorgReader::readMorg()
{
	Morg * m = nullptr;

	std::string buf;
	if (reader->readLine(buf))
	{
		std::vector<std::string> tokens = tokenize(buf, ',');

		std::vector<std::string> feedBehavior = tokenize(tokens[4], ' ');
		std::vector<char> feedList;
		for (int i = 1; i < feedBehavior.size(); ++i) {
			feedList.push_back(feedBehavior[i][0]);
		}


		m = factory->createMorg(tokens[0][0], atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), tokens[3],
			feedBehavior[0], feedList, tokens[5] );
	}

	return m;
}
