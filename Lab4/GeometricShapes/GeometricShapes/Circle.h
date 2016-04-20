#pragma once
#include "../GeometricShapes/SolidShape.h"

class CCircle final : public CSolidShape
{
public:
	CCircle(Vector2f const &pos, float radius
		, Color const &lineColor, Color const &fillColor);
	float GetRadius()const;
	Vector2f GetPosition()const;

	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string ToString()const override;
private:
	Vector2f m_pos;
	float m_radius;
};