#include "stdafx.h"
#include "ShapesContainer.h"
#include "LineSegment.h"
#include "Triangle.h"
#include <iostream>
#include "LineSegment_view.h"
#include "Circle_view.h"
#include "Rectangle_view.h"
#include "Triangle_view.h"

using namespace std;

void CShapesContainer::PushPoint(Vector2f const & pos)
{
	m_shapes.push_back(make_shared<CPoint>(pos));
}

void CShapesContainer::PushLineSegment(Vector2f const & firstPointPos, Vector2f const & secondPointPos, Color const & lineColor)
{
	m_shapes.push_back(make_shared<CLineSegment>(firstPointPos, secondPointPos, lineColor));
	
	m_viewShapes.push_back(make_shared<CLineSegmentView>(firstPointPos, secondPointPos, lineColor));
}

void CShapesContainer::PushCircle(Vector2f const & pos, float radius, Color const & lineColor, Color const & fillColor)
{
	m_shapes.push_back(make_shared<CCircle>(pos, radius, lineColor, fillColor));

	m_viewShapes.push_back(make_shared<CCircleView>(pos, radius, lineColor, fillColor));
}

void CShapesContainer::PushRectangle(Vector2f const & topLeftPointPos, Vector2f const & rectProportion
	, Color const & lineColor, Color const & fillColor)
{
	m_shapes.push_back(make_shared<CRectangle>(topLeftPointPos, rectProportion, lineColor, fillColor));

	m_viewShapes.push_back(make_shared<CRectangleView>(topLeftPointPos, rectProportion, lineColor, fillColor));
}

void CShapesContainer::PushTriangle(Vector2f const & topVertexPos, Vector2f const & leftVertexPos
	, Vector2f const & rightVertexPos, Color const & lineColor, Color const & fillColor)
{
	m_shapes.push_back(make_shared<CTriangle>(topVertexPos, leftVertexPos, rightVertexPos, lineColor, fillColor));

	m_viewShapes.push_back(make_shared<CTriangleView>(topVertexPos, leftVertexPos, rightVertexPos, lineColor, fillColor));
}

LogicShapesPtrs CShapesContainer::GetShapes()const
{
	return m_shapes;
}

ViewShapesPtrs CShapesContainer::GetViewShapes()const
{
	return m_viewShapes;
}
