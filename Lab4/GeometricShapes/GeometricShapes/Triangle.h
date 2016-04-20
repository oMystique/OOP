#pragma once
#include "../GeometricShapes/Rectangle.h"

class CTriangle final : public CSolidShape
{
public:
	CTriangle(Vector2f const &topVertexPos, Vector2f const &leftVertexPos
		, Vector2f const &rightVertexPos, Color const &lineColor, Color const &fillColor);
	Vector2f GetTopVertexPos()const;
	Vector2f GetLeftVertexPos()const;
	Vector2f GetRightVertexPos()const;

	float GetShapesSquare()const override;
	float GetShapesPerimeter()const override;
	std::string GetShapesPresentation()const override;
private:
	void CalculateTriangleSides(float &a, float &b, float &c)const;
private:
	Vector2f m_topVertexPos;
	Vector2f m_leftVertexPos;
	Vector2f m_rightVertexPos;
};