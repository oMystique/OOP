#include "stdafx.h"
#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle(Vector2f const &rectPos, Vector2f const &rectProportion, string const & lineColor, string const & fillColor)
	: m_pos(rectPos)
	, m_proportion(rectProportion)
	, m_lineColor(lineColor)
	, m_fillColor(fillColor)
{
}

float CRectangle::GetShapesSquare()const
{
	return m_proportion.x * m_proportion.y;
}

float CRectangle::GetShapesPerimeter()const
{
	return (m_proportion.x + m_proportion.y) * 2.f;
}

string CRectangle::GetShapesName()const
{
	return "Rectangle";
}

string CRectangle::GetLineColor()const
{
	return m_lineColor;
}

std::string CRectangle::GetFillColor()const
{
	return m_fillColor;
}
