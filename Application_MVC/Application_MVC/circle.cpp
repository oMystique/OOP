#include "circle.h"

CCircleFigure::CCircleFigure() 
{
	m_figure.setFillColor(Color::Yellow);
	m_figure.setOutlineThickness(GET_HALF);
	m_figure.setOutlineColor(Color::Black);
}

void CCircleFigure::ResetFigure(Vector2f const size, Vector2f const pos) 
{
	m_figure.setRadius(size.x / CIRCLE_RADIUS_CORRECTION); 
	m_figure.setOrigin(m_figure.getGlobalBounds().width / GET_HALF,
						m_figure.getGlobalBounds().height / GET_HALF);
	SetFigurePosition(pos);
}

void CCircleFigure::SetFigurePosition(Vector2f const pos) 
{
	m_figure.setPosition(pos.x, pos.y);
}

void CCircleFigure::Draw(RenderWindow &window) const 
{
	window.draw(m_figure);
}

FloatRect CCircleFigure::GetRect() const 
{
	return m_figure.getGlobalBounds();
}