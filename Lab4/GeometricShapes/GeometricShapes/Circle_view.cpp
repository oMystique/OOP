#include "stdafx.h"
#include "Circle_view.h"

CCircleView::CCircleView(Vector2f const & pos, float radius, Color const & lineColor, Color const & fillColor)
{
	m_circle.setPosition({ pos.x, pos.y });
	m_circle.setRadius(radius);
	m_circle.setOutlineColor(sf::Color(sf::Uint8(lineColor.RR), sf::Uint8(lineColor.GG), sf::Uint8(lineColor.BB)));
	m_circle.setOutlineThickness(2.f);
	m_circle.setFillColor(sf::Color(sf::Uint8(fillColor.RR), sf::Uint8(fillColor.GG), sf::Uint8(fillColor.BB)));
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_circle, states);
}
