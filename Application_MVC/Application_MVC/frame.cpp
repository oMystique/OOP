#include "frame.h"

CFrame::CFrame() 
{
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
	m_delta = { NULL, NULL };
	m_oldMousePos = { NULL, NULL };
}

void CFrame::Draw(RenderWindow &window) const
{
	window.draw(m_frameRect);
	window.draw(m_topLeftPoint);
	window.draw(m_topRightPoint);
	window.draw(m_botLeftPoint);
	window.draw(m_botRightPoint);
}

FloatRect CFrame::GetRect() const 
{
	return m_frameRect.getGlobalBounds() ;
}

void CFrame::SetFigurePosition(Vector2f const pos) 
{
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

void CFrame::ResetFigure(Vector2f const size, Vector2f const pos)
{
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

bool CFrame::IsAction(Vector2f const &mousePos) const
{
	return ((m_topLeftPoint.getGlobalBounds().contains(mousePos)) ||
		(m_topRightPoint.getGlobalBounds().contains(mousePos)) ||
		(m_botRightPoint.getGlobalBounds().contains(mousePos)) ||
		(m_botLeftPoint.getGlobalBounds().contains(mousePos)));
}

void CFrame::SetDeltaParamether(Vector2f const &mousePos)
{
	m_delta = { m_oldMousePos - mousePos };
	if (m_delta.x != m_delta.y)
	{
		m_delta.x = m_delta.y;
	}
	if ((m_botRightPoint.getGlobalBounds().contains(mousePos)) || (m_botLeftPoint.getGlobalBounds().contains(mousePos))) 
	{
		m_delta.x = -m_delta.x;
		m_delta.y = -m_delta.y;
	}
	if (m_delta.x < 0)
	{
		m_delta = { -1.f, -1.f };
	}
	else 
	{
		m_delta = { 1.f, 1.f };
	}
}

FloatRect CFrame::FrameEvent(Vector2f const &mousePos, Vector2f pos, Vector2f size)
{
	SetDeltaParamether(mousePos);
	size += m_delta;
	return { pos.x, pos.y, size.x, size.y };
}

Vector2f CFrame::GetStartMousePos() const 
{
	return m_oldMousePos;
}

void CFrame::SetStartMousePos(Vector2f const &mousePos)
{
	m_oldMousePos = mousePos;
}