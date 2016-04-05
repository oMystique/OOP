#pragma once

#include "Point.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, std::string const &lineColor);
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesName()const override;
	std::string GetLineColor()const override;
private:
	float GetLengthOfTheLineSegment()const;
private:
	Vector2f const m_firstPointPos;
	Vector2f const m_secondPointPos;
	std::string m_lineColor;
};