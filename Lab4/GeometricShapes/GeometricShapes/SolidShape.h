#pragma once
#include "../GeometricShapes/Shape.h"

class ISolidShape: public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual Color GetFillColor()const = 0;
};

class CSolidShape : public ISolidShape
{
public:
	Color GetFillColor()const override;
	Color GetLineColor()const override;
protected:
	Color m_fillColor;
	Color m_lineColor;
};