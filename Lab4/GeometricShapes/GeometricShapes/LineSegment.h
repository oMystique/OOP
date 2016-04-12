#pragma once

#include "Point.h"

class CLineSegment final : public CShape
{
public:
	CLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, Color const &lineColor);
	float GetShapesPerimeter()const override;
	std::string GetShapesPresentation()const override;
private:
	float GetLengthOfTheLineSegment()const;
private:
	Vector2f m_firstPointPos;
	Vector2f m_secondPointPos;
};