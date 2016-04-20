#include "stdafx.h"
#include "Rectangle_view.h"

CRectangleView::CRectangleView(Vector2f const & topLeftPointPos, Vector2f const & rectProportion, Color const & lineColor, Color const & fillColor)
{
	m_rect.setPosition({ topLeftPointPos.x, topLeftPointPos.y });
	m_rect.setSize({ rectProportion.x, rectProportion.y });
	m_rect.setOutlineColor(GetSFColor(lineColor));
	m_rect.setOutlineThickness(2.f);
	m_rect.setFillColor(GetSFColor(fillColor));
}

void CRectangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rect, states);
}
