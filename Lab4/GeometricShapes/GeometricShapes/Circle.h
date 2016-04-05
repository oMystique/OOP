#pragma once
#include "SolidShape.h"

class CCircle final : public ISolidShape
{
public:
	CCircle(Vector2f const &pos, float radius, std::string const &lineColor, std::string const &fillColor);
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesName()const override;
	std::string GetLineColor()const override;
	std::string GetFillColor()const override;
private:
	Vector2f const m_pos;
	float const m_radius;
	std::string const m_lineColor;
	std::string const m_fillColor;
};