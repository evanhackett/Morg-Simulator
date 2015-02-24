#pragma once
#include "Location.h"

class Observer
{
public:
    virtual void Update(Location *location) = 0;
};