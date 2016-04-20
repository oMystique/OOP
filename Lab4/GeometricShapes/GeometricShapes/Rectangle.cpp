#include "stdafx.h"
#include "../GeometricShapes/Rectangle.h"

using namespace std;

CRectangle::CRectangle(Vector2f const &rectPos, Vector2f const &rectProportion
		, Color const & lineColor, Color const & fillColor)
	: m_pos(rectPos)
	, m_proportions(rectProportion)
{
	m_fillColor = fillColor;
	m_lineColor = lineColor;
}

Vector2f CRectangle::GetProportions()const
{
	return m_proportions;
}

Vector2f CRectangle::GetPosition()const
{
	return m_pos;
}

float CRectangle::GetShapesSquare()const
{
	return m_proportions.x * m_proportions.y;
}

float CRectangle::GetShapesPerimeter()const
{
	return (m_proportions.x + m_proportions.y) * 2.f;
}

string CRectangle::ToString() const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "Rectangle: " << "Pos <" << m_pos.x << "," << m_pos.y
		<< ">; Size <" << m_proportions.x << "," << m_proportions.y << ">; " << "P = "
		<< GetShapesPerimeter() << "; " << "S = " << GetShapesSquare();

	return strm.str();
}
