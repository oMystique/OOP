#include "stdafx.h"
#include "../GeometricShapes/LineSegment.h"
#include <math.h>

using namespace std;

CLineSegment::CLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, Color const &lineColor)
	: m_firstPointPos(firstPointPos)
	, m_secondPointPos(secondPointPos)
	, m_lineColor(lineColor)
{
}

Vector2f CLineSegment::GetPosOfFirstPoint()const
{
	return m_firstPointPos;
}

Vector2f CLineSegment::GetPosOfSecondPoint()const
{
	return m_secondPointPos;
}

float CLineSegment::GetShapesPerimeter()const
{
	return GetLengthOfTheLineSegment();
}

string CLineSegment::ToString()const
{
	std::ostringstream strm;
	strm.setf(ios_base::fixed, ios_base::floatfield);
	strm << setprecision(2);

	strm << "LineSegment: " << "First point pos <" << m_firstPointPos.x << "," << m_firstPointPos.y
		<< ">, Second point pos <" << m_secondPointPos.x << "," << m_secondPointPos.y << ">; P = "
		<< GetShapesPerimeter() << "; " << "S = " << GetShapesSquare();

	return strm.str();
}

float CLineSegment::GetShapesSquare() const
{
	return 0.0f;
}

Color CLineSegment::GetLineColor() const
{
	return m_lineColor;
}

float CLineSegment::GetLengthOfTheLineSegment()const
{
	return sqrtf(pow((m_firstPointPos.x - m_secondPointPos.x), 2) + pow((m_firstPointPos.y - m_secondPointPos.y), 2));
}
