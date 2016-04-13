#include "stdafx.h"
#include "Rectangle_view.h"

CRectangleView::CRectangleView(Vector2f const & topLeftPointPos, Vector2f const & rectProportion, Color const & lineColor, Color const & fillColor)
{
	m_rect.setPosition({ topLeftPointPos.x, topLeftPointPos.y });
	m_rect.setSize({ rectProportion.x, rectProportion.y });
	m_rect.setOutlineColor(sf::Color(sf::Uint8(lineColor.RR), sf::Uint8(lineColor.GG), sf::Uint8(lineColor.BB)));
	m_rect.setOutlineThickness(2.f);
	m_rect.setFillColor(sf::Color(sf::Uint8(fillColor.RR), sf::Uint8(fillColor.GG), sf::Uint8(fillColor.BB)));
}

void CRectangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rect, states);
}
