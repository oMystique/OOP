#pragma once
#include "../GeometricShapes/Shape.h"

class CPoint final : public IShape
{
public:
	CPoint(Vector2f const & pos);
	Vector2f GetPointPosition()const;

	std::string ToString()const override;
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	Color GetLineColor()const override;
private:
	Vector2f m_pos;
};