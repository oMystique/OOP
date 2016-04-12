#pragma once
#include "Circle.h"

class CRectangle final : public CSolidShape
{
public:
	CRectangle(Vector2f const &topLeftPointPos, Vector2f const &rectProportion
		, Color const &lineColor, Color const &fillColor);
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesPresentation()const override;
private:
	Vector2f m_pos;
	Vector2f m_proportion;
};