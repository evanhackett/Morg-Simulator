#pragma once

#include "Reader.h"

class ReaderDecorator :
	public Reader
{
public:
	ReaderDecorator(Reader * reader) { this->reader = reader; }

	virtual ~ReaderDecorator()
	{
		if (reader != NULL) {
			reader->close();
			delete reader;
		}
	}

	virtual bool open() { return reader->open(); }
	virtual void close() { reader->close(); }
	virtual bool readLine(std::string & buf) { return reader->readLine(buf); }

protected:
	Reader * reader;
};

