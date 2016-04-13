#pragma once
#include <string>
#include <sstream>
#include <iomanip>

struct Color
{
	int RR = 0;
	int GG = 0;
	int BB = 0;
};

struct Vector2f
{
	float x;
	float y;
};

class IShape
{
public:
	~IShape() = default;
	virtual float GetShapesSquare()const = 0;
	virtual float GetShapesPerimeter()const = 0;
	virtual std::string GetShapesPresentation()const = 0;
	virtual Color GetLineColor()const = 0;
};

class CShape: public IShape
{
public:
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	Color GetLineColor()const override;
protected:
	float m_square;
	float m_perimeter;
	Color m_lineColor;
};