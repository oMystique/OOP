#pragma once

#include "../GeometricShapes/Point.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, Color const &lineColor);
	Vector2f GetPosOfFirstPoint()const;
	Vector2f GetPosOfSecondPoint()const;

	float GetShapesPerimeter()const override;
	std::string ToString()const override;
	float GetShapesSquare()const override;
	Color GetLineColor()const override;
private:
	float GetLengthOfTheLineSegment()const;
private:
	Vector2f m_firstPointPos;
	Vector2f m_secondPointPos;
	Color m_lineColor;
};