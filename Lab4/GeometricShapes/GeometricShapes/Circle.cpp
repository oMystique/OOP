#include "stdafx.h"

#define _USE_MATH_DEFINES

#include "Circle.h"
#include <cmath> 

using namespace std;

CCircle::CCircle(Vector2f const &pos, float radius, string const &lineColor, string const &fillColor)
	: m_pos(pos)
	, m_radius(radius)
	, m_lineColor(lineColor)
	, m_fillColor(fillColor)
{
}

float CCircle::GetShapesSquare()const
{
	return static_cast<float>(M_PI) * powf(m_radius, 2.f);
}

float CCircle::GetShapesPerimeter()const
{
	return 2.f * static_cast<float>(M_PI) * m_radius;
}

string CCircle::GetShapesName()const
{
	return "Circle";
}

string CCircle::GetLineColor()const
{
	return m_lineColor;
}

string CCircle::GetFillColor()const
{
	return m_fillColor;
}
