#include "stdafx.h"
#include "Circle_view.h"

CCircleView::CCircleView(Vector2f const & pos, float radius, Color const & lineColor, Color const & fillColor)
{
	m_circle.setPosition({ pos.x, pos.y });
	m_circle.setRadius(radius);
	m_circle.setOutlineColor(GetSFColor(lineColor));
	m_circle.setOutlineThickness(2.f);
	m_circle.setFillColor(GetSFColor(fillColor));
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(m_circle, states);
}
