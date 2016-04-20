#include "stdafx.h"
#include "Triangle_view.h"

CTriangleView::CTriangleView(Vector2f const & topVertexPos, Vector2f const & leftVertexPos, Vector2f const & rightVertexPos, Color const & lineColor, Color const & fillColor)
{
	m_triangle.setPointCount(3);
	m_triangle.setPoint(0, { topVertexPos.x, topVertexPos.y });
	m_triangle.setPoint(1, { leftVertexPos.x, leftVertexPos.y });
	m_triangle.setPoint(2, { rightVertexPos.x, rightVertexPos.y });
	m_triangle.setOutlineColor(GetSFColor(lineColor));
	m_triangle.setOutlineThickness(2.f);
	m_triangle.setFillColor(GetSFColor(fillColor));
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(m_triangle, states);
}
