#pragma once
#include <string>
#include <sstream>
#include <iomanip>

struct Color
{
	Color() = default;
	Color(int r, int g, int b)
		: r(r)
		, g(g)
		, b(b)
	{};

	int r = 0;
	int g = 0;
	int b = 0;
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
	virtual ~IShape() = default;
	virtual float GetShapesSquare()const = 0;
	virtual float GetShapesPerimeter()const = 0;
	virtual std::string ToString()const = 0;
	virtual Color GetLineColor()const = 0;
};