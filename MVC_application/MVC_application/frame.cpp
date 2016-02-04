#include "frame.h"

CFrame::CFrame() {
	m_frameRect.setFillColor(DEFAULT_FRAME_COLOR);
	m_frameRect.setOutlineColor(DEFAULT_FRAME_OUTLINE_COLOR);
	m_frameRect.setOutlineThickness(GET_HALF);
	m_topLeftPoint.setRadius(FRAME_POINT_RADIUS);
	m_topLeftPoint.setFillColor(Color::Red);
	m_topRightPoint.setRadius(FRAME_POINT_RADIUS);
	m_topRightPoint.setFillColor(Color::Red);
	m_botLeftPoint.setRadius(FRAME_POINT_RADIUS);
	m_botLeftPoint.setFillColor(Color::Red);
	m_botRightPoint.setRadius(FRAME_POINT_RADIUS);
	m_botRightPoint.setFillColor(Color::Red);
}

void CFrame::Draw(RenderWindow &window) {
	window.draw(m_frameRect);
	window.draw(m_topLeftPoint);
	window.draw(m_topRightPoint);
	window.draw(m_botLeftPoint);
	window.draw(m_botRightPoint);
}


FloatRect CFrame::GetRect() {
	return{ NULL, NULL, NULL, NULL };
}

void CFrame::SetFigurePosition(Vector2f const pos) {
	m_frameRect.setPosition(pos);
	m_topLeftPoint.setPosition(m_frameRect.getGlobalBounds().left,
		m_frameRect.getGlobalBounds().top);
	m_topRightPoint.setPosition(m_frameRect.getGlobalBounds().left +
		m_frameRect.getGlobalBounds().width,
		m_frameRect.getGlobalBounds().top);
	m_botLeftPoint.setPosition(m_frameRect.getGlobalBounds().left,
		m_frameRect.getGlobalBounds().top +
		m_frameRect.getGlobalBounds().height);
	m_botRightPoint.setPosition(m_frameRect.getGlobalBounds().left +
		m_frameRect.getGlobalBounds().width,
		m_frameRect.getGlobalBounds().top +
		m_frameRect.getGlobalBounds().height);
}

void CFrame::ResetFigure(Vector2f const size, Vector2f const pos) {
	m_frameRect.setSize(size);
	m_topLeftPoint.setOrigin(m_topLeftPoint.getGlobalBounds().width / GET_HALF,
		m_topLeftPoint.getGlobalBounds().height / GET_HALF);
	m_topRightPoint.setOrigin(m_topLeftPoint.getGlobalBounds().width / GET_HALF,
		m_topLeftPoint.getGlobalBounds().height / GET_HALF);
	m_botLeftPoint.setOrigin(m_topLeftPoint.getGlobalBounds().width / GET_HALF,
		m_topLeftPoint.getGlobalBounds().height / GET_HALF);
	m_botRightPoint.setOrigin(m_topLeftPoint.getGlobalBounds().width / GET_HALF,
		m_topLeftPoint.getGlobalBounds().height / GET_HALF);
	SetFigurePosition(pos);
}