#pragma once
#include "SolidShape.h"

class CRectangle final : public ISolidShape
{
public:
	CRectangle(Vector2f const &topLeftPointPos, Vector2f const &rectProportion, std::string const &lineColor, std::string const &fillColor);
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesName()const override;
	std::string GetLineColor()const override;
	std::string GetFillColor()const override;
private:
	Vector2f const m_pos;
	Vector2f const m_proportion;
	std::string const m_lineColor;
	std::string const m_fillColor;
};