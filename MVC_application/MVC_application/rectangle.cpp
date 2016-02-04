#include "rectangle.h"


CRectangleFigure::CRectangleFigure() {
	m_figure.setFillColor(Color::Blue);
	m_figure.setOutlineThickness(GET_HALF);
	m_figure.setOutlineColor(Color::Black);
}

void CRectangleFigure::ResetFigure(Vector2f const size, Vector2f const pos) {
	m_figure.setSize(Vector2f(size.x * RECTANGLE_SIZE_CORRECTION.x,
							size.y * RECTANGLE_SIZE_CORRECTION.y));
	m_figure.setOrigin(m_figure.getGlobalBounds().width / GET_HALF,
					m_figure.getGlobalBounds().height / GET_HALF);
	SetFigurePosition(pos);
}

void CRectangleFigure::SetFigurePosition(Vector2f const pos) {
	m_figure.setPosition(pos.x, pos.y);
}

void CRectangleFigure::Draw(RenderWindow &window) const {
	window.draw(m_figure);
}

FloatRect CRectangleFigure::GetRect() const {
	return m_figure.getGlobalBounds();
}