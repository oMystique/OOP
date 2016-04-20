#include "stdafx.h"
#include "LineSegment_view.h"

CLineSegmentView::CLineSegmentView(Vector2f const & firstPointPos, Vector2f const & secondPointPos, Color const & lineColor)
{
	m_line[0].position = sf::Vector2f(firstPointPos.x, firstPointPos.y);
	m_line[1].position = sf::Vector2f(secondPointPos.x, secondPointPos.y);
	m_line[0].color = GetSFColor(lineColor);
	m_line[1].color = GetSFColor(lineColor);
}

void CLineSegmentView::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(m_line, 3, sf::Lines, states);
}
