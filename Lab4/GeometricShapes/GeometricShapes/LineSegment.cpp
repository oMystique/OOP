#include "stdafx.h"
#include "LineSegment.h"
#include <math.h>

using namespace std;

CLineSegment::CLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, Color const &lineColor)
	: m_firstPointPos(firstPointPos)
	, m_secondPointPos(secondPointPos)
{
	m_lineColor = lineColor;
	m_square = 0.0f;
}

float CLineSegment::GetShapesPerimeter()const
{
	return GetLengthOfTheLineSegment();
}

string CLineSegment::GetShapesPresentation()const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "LineSegment: " << "First point pos <" << m_firstPointPos.x << "," << m_firstPointPos.y
		<< ">, Second point pos <" << m_secondPointPos.x << "," << m_secondPointPos.y << ">; P = "
		<< GetShapesPerimeter() << "; " << "S = " << GetShapesSquare();

	return strm.str();
}

float CLineSegment::GetLengthOfTheLineSegment()const
{
	return sqrtf(pow((m_firstPointPos.x - m_secondPointPos.x), 2) + pow((m_firstPointPos.y - m_secondPointPos.y), 2));
}
