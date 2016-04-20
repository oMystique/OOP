#include "stdafx.h"
#include "../GeometricShapes/Point.h"
#include "Point.h"

using namespace std;

CPoint::CPoint(Vector2f const &pos)
	:m_pos(pos)
{
}

string CPoint::ToString() const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "Point: " << "Pos <" << m_pos.x << "," << m_pos.y
		<< ">; P = " << GetShapesPerimeter()
		<< "; S = " << GetShapesSquare();

	return strm.str();
}

float CPoint::GetShapesSquare() const
{
	return 0.0f;
}

float CPoint::GetShapesPerimeter() const
{
	return 0.0f;
}

Color CPoint::GetLineColor() const
{
	return Color(0, 0, 0);
}

Vector2f CPoint::GetPointPosition() const
{
	return m_pos;
}
