#include "stdafx.h"

#define _USE_MATH_DEFINES

#include "Circle.h"
#include <cmath> 

using namespace std;

CCircle::CCircle(Vector2f const &pos, float radius
		, Color const &lineColor, Color const &fillColor)
	: m_pos(pos)
	, m_radius(radius)
{
	m_lineColor = lineColor;
	m_fillColor = fillColor;
}

float CCircle::GetShapesSquare()const
{
	return static_cast<float>(M_PI) * powf(m_radius, 2.f);
}

float CCircle::GetShapesPerimeter()const
{
	return 2.f * static_cast<float>(M_PI) * m_radius;
}

string CCircle::GetShapesPresentation() const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "Circle: " << "Pos <" << m_pos.x <<  "," << m_pos.y
		<< ">; Radius = " << m_radius << "; P = " << GetShapesPerimeter()
		<<  "; S = " << GetShapesSquare();

	return strm.str();
}
