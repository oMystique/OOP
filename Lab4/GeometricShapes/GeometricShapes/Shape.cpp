#include "stdafx.h"
#include "Shape.h"

using namespace std;

float CShape::GetShapesSquare() const
{
	return m_square;
}

float CShape::GetShapesPerimeter() const
{
	return m_perimeter;
}

Color CShape::GetLineColor() const
{
	return m_lineColor;
}
