#pragma once
#include "SolidShape.h"

class CTriangle final : public ISolidShape
{
public:
	CTriangle(Vector2f const &topVertexPos, Vector2f const &leftVertexPos, Vector2f const &rightVertexPos, std::string const &lineColor, std::string const &fillColor);
	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesName()const override;
	std::string GetLineColor()const override;
	std::string GetFillColor()const override;
private:
	void CalculateTriangleSides(float &a, float &b, float &c)const;
private:
	Vector2f const m_topVertexPos;
	Vector2f const m_leftVertexPos;
	Vector2f const m_rightVertexPos;
	std::string const m_lineColor;
	std::string const m_fillColor;
};