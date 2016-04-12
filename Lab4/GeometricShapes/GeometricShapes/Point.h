#pragma once
#include "Shape.h"

class CPoint final : public CShape
{
public:
	CPoint(Vector2f const & pos, Color const &lineColor);
	std::string GetShapesPresentation()const override;
private:
	Vector2f m_pos;
};