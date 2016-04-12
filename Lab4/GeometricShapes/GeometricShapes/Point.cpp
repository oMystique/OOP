#include "stdafx.h"
#include "Point.h"

using namespace std;

CPoint::CPoint(Vector2f const &pos, Color const &lineColor)
	:m_pos(pos)
{
	m_lineColor = lineColor;
	m_perimeter = 0.f;
	m_square = 0.f;
}

string CPoint::GetShapesPresentation() const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "Point: " << "Pos <" << m_pos.x << "," << m_pos.y
		<< ">; P = " << GetShapesPerimeter()
		<< "; S = " << GetShapesSquare();

	return strm.str();
}
