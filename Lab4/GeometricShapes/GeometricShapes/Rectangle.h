#pragma once
#include "../GeometricShapes/Circle.h"

class CRectangle final : public CSolidShape
{
public:
	CRectangle(Vector2f const &topLeftPointPos, Vector2f const &rectProportion
		, Color const &lineColor, Color const &fillColor);
	Vector2f GetProportions()const;
	Vector2f GetPosition()const;

	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string ToString()const override;
private:
	Vector2f m_pos;
	Vector2f m_proportions;
};