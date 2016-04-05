#include "stdafx.h"
#include "Triangle.h"

using namespace std;

CTriangle::CTriangle(Vector2f const &topVertexPos, Vector2f const &leftVertexPos, Vector2f const &rightVertexPos, std::string const &lineColor, string const &fillColor)
	: m_topVertexPos(topVertexPos)
	, m_leftVertexPos(leftVertexPos)
	, m_rightVertexPos(rightVertexPos)
	, m_lineColor(lineColor)
	, m_fillColor(fillColor)
{
}

void CTriangle::CalculateTriangleSides(float & a, float & b, float & c)const
{
	a = sqrtf(pow((m_topVertexPos.x - m_leftVertexPos.x), 2) + pow((m_topVertexPos.y - m_leftVertexPos.y), 2));

	b = sqrtf(pow((m_topVertexPos.x - m_rightVertexPos.x), 2) + pow((m_topVertexPos.y - m_rightVertexPos.y), 2));

	c = sqrtf(pow((m_rightVertexPos.x - m_leftVertexPos.x), 2) + pow((m_rightVertexPos.y - m_leftVertexPos.y), 2));
}

float CTriangle::GetShapesSquare()const
{
	float perimeterHalf = GetShapesPerimeter();

	float a;
	float b;
	float c;

	CalculateTriangleSides(a, b, c);

	return sqrtf(perimeterHalf*(perimeterHalf - a)*(perimeterHalf - b)*(perimeterHalf - c));
}

float CTriangle::GetShapesPerimeter()const
{
	float a;
	float b;
	float c;
	CalculateTriangleSides(a, b, c);

	return a + b + c;
}

string CTriangle::GetShapesName()const
{
	return "Triangle";
}

string CTriangle::GetLineColor()const
{
	return m_lineColor;
}

string CTriangle::GetFillColor()const
{
	return m_fillColor;
}
