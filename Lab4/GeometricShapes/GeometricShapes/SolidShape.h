#pragma once
#include "Shape.h"

class ISolidShape
{
public:
	virtual ~ISolidShape() = default;
	virtual Color GetFillColor()const = 0;
};

class CSolidShape : public ISolidShape, public CShape
{
public:
	Color GetFillColor()const override;
protected:
	Color m_fillColor;
};