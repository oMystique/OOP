#pragma once
#include "Shape.h"

class ISolidShape: public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual std::string GetFillColor()const = 0;
};