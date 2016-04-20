#pragma once
#include <string>
#include <sstream>
#include <iomanip>

struct Color
{
	Color() = default;
	Color(int rr, int gg, int bb)
		: RR(rr)
		, GG(gg)
		, BB(bb)
	{};
	int RR = 0;
	int GG = 0;
	int BB = 0;
};

struct Vector2f
{
	Vector2f() = default;
	Vector2f(float tempX, float tempY)
		: x(tempX)
		, y(tempY)
	{};
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