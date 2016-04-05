#pragma once
#include <string>

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
	virtual std::string GetShapesName()const = 0;
	virtual std::string GetLineColor()const = 0;
};