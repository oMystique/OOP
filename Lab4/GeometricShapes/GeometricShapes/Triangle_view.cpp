#include "stdafx.h"
#include "Triangle_view.h"

CTriangleView::CTriangleView(Vector2f const & topVertexPos, Vector2f const & leftVertexPos, Vector2f const & rightVertexPos, Color const & lineColor, Color const & fillColor)
{
	m_triangle.setPointCount(3);
	m_triangle.setPoint(0, { topVertexPos.x, topVertexPos.y });
	m_triangle.setPoint(1, { leftVertexPos.x, leftVertexPos.y });
	m_triangle.setPoint(2, { rightVertexPos.x, rightVertexPos.y });
	m_triangle.setOutlineColor(sf::Color(sf::Uint8(lineColor.RR), sf::Uint8(lineColor.GG), sf::Uint8(lineColor.BB)));
	m_triangle.setFillColor(sf::Color(sf::Uint8(fillColor.RR), sf::Uint8(fillColor.GG), sf::Uint8(fillColor.BB)));
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_triangle, states);
}
