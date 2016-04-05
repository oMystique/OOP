#pragma once
#include "Shape.h"

class CPoint final : public IShape
{
public:
	CPoint(Vector2f const & pos, std::string const &lineColor);
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesName()const override;
	std::string GetLineColor()const override;
	Vector2f GetPosition()const;
private:
	std::string const m_lineColor;
	Vector2f const m_pos;
};