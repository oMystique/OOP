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
	m_delta = { OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS };
	m_oldMousePos = { OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS };
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
	return ((PointSelected(m_topLeftPoint, mousePos)) ||
		(PointSelected(m_topRightPoint, mousePos)) ||
		(PointSelected(m_botRightPoint, mousePos)) ||
		(PointSelected(m_botLeftPoint, mousePos)));
}

bool CFrame::PointSelected(CircleShape const &shape, Vector2f const &mousePos) const
{
	return (shape.getGlobalBounds().contains(mousePos));
}

bool CFrame::BotPointsSelected(Vector2f const &mousePos) const
{
	return ((PointSelected(m_botRightPoint, mousePos)) ||
		(PointSelected(m_botLeftPoint, mousePos)));
}

void CFrame::CorrectionDeltaWithPressingPos(Vector2f const &mousePos)
{
	if (BotPointsSelected(mousePos))
	{
		if (!(PointSelected(m_botLeftPoint, mousePos)))
		{
			m_delta.x = -m_delta.x;
		}
		m_delta.y = -m_delta.y;
	}
	else if (PointSelected(m_topRightPoint, mousePos))
	{
		m_delta.x = -m_delta.x;
	}
}

void CFrame::SetDeltaParamether(Vector2f const &mousePos)
{
	m_delta = { m_oldMousePos - mousePos };
	m_delta.x /= 10;
	m_delta.y /= 10;
	CorrectionDeltaWithPressingPos(mousePos);
}

bool CFrame::CursosIsMovedEnough(Vector2f const &mousePos) const
{
	return (abs(m_oldMousePos.x - mousePos.x) > FRAME_POINT_RADIUS / GET_HALF) ||
		(abs(m_oldMousePos.y - mousePos.y) > FRAME_POINT_RADIUS / GET_HALF);
}

FloatRect CFrame::FrameEvent(Vector2f const &mousePos, Vector2f pos, Vector2f size)
{
	if (CursosIsMovedEnough(mousePos))
	{
		SetDeltaParamether(mousePos);
		size += m_delta;
		//TODO: pos.
	}
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