#include "stdafx.h"
#include "LineSegment.h"
#include <math.h>

using namespace std;

CLineSegment::CLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, string const &lineColor)
	: m_firstPointPos(firstPointPos)
	, m_secondPointPos(secondPointPos)
	, m_lineColor(lineColor)
{
}

float CLineSegment::GetShapesSquare()const
{
	return 0.0f;
}

float CLineSegment::GetShapesPerimeter()const
{
	return GetLengthOfTheLineSegment();
}

string CLineSegment::GetShapesName()const
{
	return "Line Segment";
}

string CLineSegment::GetLineColor()const
{
	return m_lineColor;
}

float CLineSegment::GetLengthOfTheLineSegment()const
{
	return sqrtf(pow((m_firstPointPos.x - m_secondPointPos.x), 2) + pow((m_firstPointPos.y - m_secondPointPos.y), 2));
}
