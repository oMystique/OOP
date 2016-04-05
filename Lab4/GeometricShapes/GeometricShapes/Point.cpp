#include "stdafx.h"
#include "Point.h"

using namespace std;

CPoint::CPoint(Vector2f const &pos, string const &lineColor)
	: m_pos(pos)
	, m_lineColor(lineColor)
{
}

float CPoint::GetShapesSquare()const
{
	return 0.0f;
}

float CPoint::GetShapesPerimeter()const
{
	return 0.0f;
}

string CPoint::GetShapesName()const
{
	return "Point";
}

string CPoint::GetLineColor()const
{
	return m_lineColor;
}

Vector2f CPoint::GetPosition()const
{
	return m_pos;
}
