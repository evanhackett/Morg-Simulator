#pragma once
#include "readerdecorator.h"
#include "Morg.h"
#include "MorgFactory.h"

class MorgReader :
	public ReaderDecorator
{
public:
	MorgReader(MorgFactory * factory, Reader * reader);
	virtual ~MorgReader();

	Morg * readMorg();

private:
	MorgFactory * factory;
};

