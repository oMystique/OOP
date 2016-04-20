#include "stdafx.h"
#include "Circle_view.h"

CCircleView::CCircleView(Vector2f const & pos, float radius, Color const & lineColor, Color const & fillColor)
{
	m_circle.setPosition({ pos.x, pos.y });
	m_circle.setRadius(radius);
	m_circle.setOutlineColor(sf::Color(sf::Uint8(lineColor.r), sf::Uint8(lineColor.g), sf::Uint8(lineColor.b)));
	m_circle.setOutlineThickness(2.f);
	m_circle.setFillColor(sf::Color(sf::Uint8(fillColor.r), sf::Uint8(fillColor.g), sf::Uint8(fillColor.b)));
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_circle, states);
}
