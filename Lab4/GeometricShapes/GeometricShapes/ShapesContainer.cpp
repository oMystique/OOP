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

void CShapesContainer::PushPoint(Vector2f const & pos, Color const & lineColor)
{
	auto point = make_shared<CPoint>(pos, lineColor);
	m_shapes.push_back(point);
}

void CShapesContainer::PushLineSegment(Vector2f const & firstPointPos, Vector2f const & secondPointPos, Color const & lineColor)
{
	auto line = make_shared<CLineSegment>(firstPointPos, secondPointPos, lineColor);
	m_shapes.push_back(line);
	
	auto lineView = make_shared<CLineSegmentView>(firstPointPos, secondPointPos, lineColor);
	m_viewShapes.push_back(lineView);
}

void CShapesContainer::PushCircle(Vector2f const & pos, float radius, Color const & lineColor, Color const & fillColor)
{
	auto circle = make_shared<CCircle>(pos, radius, lineColor, fillColor);
	m_shapes.push_back(circle);

	auto circleView = make_shared<CCircleView>(pos, radius, lineColor, fillColor);
	m_viewShapes.push_back(circleView);
}

void CShapesContainer::PushRectangle(Vector2f const & topLeftPointPos, Vector2f const & rectProportion
	, Color const & lineColor, Color const & fillColor)
{
	auto rect = make_shared<CRectangle>(topLeftPointPos, rectProportion, lineColor, fillColor);
	m_shapes.push_back(rect);

	auto rectView = make_shared<CRectangleView>(topLeftPointPos, rectProportion, lineColor, fillColor);
	m_viewShapes.push_back(rectView);
}

void CShapesContainer::PushTriangle(Vector2f const & topVertexPos, Vector2f const & leftVertexPos
	, Vector2f const & rightVertexPos, Color const & lineColor, Color const & fillColor)
{
	auto triangle = make_shared<CTriangle>(topVertexPos, leftVertexPos, rightVertexPos, lineColor, fillColor);
	m_shapes.push_back(triangle);

	auto triangleView = make_shared<CTriangleView>(topVertexPos, leftVertexPos, rightVertexPos, lineColor, fillColor);
	m_viewShapes.push_back(triangleView);
}

ShapesPtrs CShapesContainer::GetShapes()const
{
	return m_shapes;
}

ViewShapesPtrs CShapesContainer::GetViewShapes()const
{
	return m_viewShapes;
}
