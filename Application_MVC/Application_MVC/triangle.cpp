#include "triangle.h"

CTriangleFigure::CTriangleFigure()
{
	m_figure.setFillColor(Color::Red);
	m_figure.setOutlineThickness(GET_HALF);
	m_figure.setOutlineColor(Color::Black);
}

void CTriangleFigure::ResetFigure(Vector2f const size, Vector2f const pos)
{
	m_figure.setPointCount(3);
	m_figure.setPoint(0, sf::Vector2f(size.x / TRIANGLE_SIZE_CORRECTION, 0));
	m_figure.setPoint(1, sf::Vector2f(0, size.y / GET_HALF));
	m_figure.setPoint(2, sf::Vector2f(size.y / GET_HALF, size.y / GET_HALF));
	m_figure.setOrigin(m_figure.getGlobalBounds().width / GET_HALF,
		m_figure.getGlobalBounds().height / GET_HALF);
	SetFigurePosition(pos);
}

void CTriangleFigure::SetFigurePosition(Vector2f const pos)
{
	m_figure.setPosition(pos.x, pos.y);
}

void CTriangleFigure::Draw(RenderWindow &window) const
{
	window.draw(m_figure);
}

FloatRect CTriangleFigure::GetRect() const
{
	return m_figure.getGlobalBounds();
}