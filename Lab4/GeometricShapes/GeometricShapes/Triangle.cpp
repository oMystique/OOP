#include "stdafx.h"
#include "../GeometricShapes/Triangle.h"

using namespace std;

CTriangle::CTriangle(Vector2f const &topVertexPos, Vector2f const &leftVertexPos
		, Vector2f const &rightVertexPos, Color const &lineColor, Color const &fillColor)
	: m_topVertexPos(topVertexPos)
	, m_leftVertexPos(leftVertexPos)
	, m_rightVertexPos(rightVertexPos)
{
	m_lineColor = lineColor;
	m_fillColor = fillColor;
}

Vector2f CTriangle::GetTopVertexPos() const
{
	return m_topVertexPos;
}

Vector2f CTriangle::GetLeftVertexPos() const
{
	return m_leftVertexPos;
}

Vector2f CTriangle::GetRightVertexPos() const
{
	return m_rightVertexPos;
}

CTriangle::Sides CTriangle::CalculateTriangleSides()const
{
	float a = sqrtf(pow((m_topVertexPos.x - m_leftVertexPos.x), 2) + pow((m_topVertexPos.y - m_leftVertexPos.y), 2));

	float b = sqrtf(pow((m_topVertexPos.x - m_rightVertexPos.x), 2) + pow((m_topVertexPos.y - m_rightVertexPos.y), 2));

	float c = sqrtf(pow((m_rightVertexPos.x - m_leftVertexPos.x), 2) + pow((m_rightVertexPos.y - m_leftVertexPos.y), 2));

	return make_tuple(a, b, c);
}

float CTriangle::GetShapesSquare()const
{
	float perimeterHalf = GetShapesPerimeter() / 2.f;

	float a;
	float b;
	float c;

	tie(a, b, c) = CalculateTriangleSides();

	return sqrtf(perimeterHalf*(perimeterHalf - a)*(perimeterHalf - b)*(perimeterHalf - c));
}

float CTriangle::GetShapesPerimeter()const
{
	float a;
	float b;
	float c;

	tie(a, b, c) = CalculateTriangleSides();

	return a + b + c;
}

string CTriangle::ToString() const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "Triangle: " << "Top vertex pos <" << m_topVertexPos.x << "," << m_topVertexPos.y
		<< ">, Left vertex pos <" << m_leftVertexPos.x << "," << m_leftVertexPos.y << ">, Right Vertex Pos <"
		<< m_rightVertexPos.x << "," << m_rightVertexPos.y << ">; P = "
		<< GetShapesPerimeter() << "; S = " << GetShapesSquare();

	return strm.str();
}
