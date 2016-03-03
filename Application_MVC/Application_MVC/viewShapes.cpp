#include "viewShapes.h"

CViewShapes::CViewShapes() : m_pFrame(make_unique<CFrame>())
{
};

bool CViewShapes::ShapeWasChoosen(CShapeGraphic *figure, Vector2f const &pos,
	RenderWindow &window, bool mouseClicked) const
{
	return (figure->GetRect().contains(GetMousePos(window)) &&
		(mouseClicked) && GetIntersects(pos, figure->GetRect()));
}

FloatRect CViewShapes::ResizingFrameChoosenPoint(Vector2f const &size,
	Vector2f const &pos, RenderWindow &window)
{
	m_isFrameAction = true;
	return { m_pFrame->FrameEvent(GetMousePos(window), pos, size) };
}

bool CViewShapes::SelectedPointForResizing(unsigned index,
	bool mouseClicked, RenderWindow &window) const
{
	return ((m_pSelectedShape == m_shapes[index]) && (mouseClicked)
		&& (m_pFrame->IsAction(GetMousePos(window))));
}

bool CViewShapes::ShapeShouldBeRemoved(unsigned index, CommandType command) const
{
	return ((command == DeleteShape) && (m_shapes[index] == m_pSelectedShape));
}

FloatRect CViewShapes::RemoveShape(unsigned index)
{
	m_shapes[index]->isDeleted = true;
	return{ OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS,
		OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS };
}

bool CViewShapes::SelectedShapeIsNotSelected(unsigned index, RenderWindow &window) const
{
	return (m_pSelectedShape != m_shapes[index] &&
		(!m_pSelectedShape->GetRect().contains(GetMousePos(window))));
}

void CViewShapes::ChangeSelectedShape(unsigned index)
{
	m_pSelectedShape.release();
	m_pSelectedShape.reset(m_shapes[index].get());
}

void CViewShapes::SetDiffBetweenShapePosAndMousePos(Vector2f const &pos, RenderWindow &window)
{
	if (m_diffBetweenShapePosAndMousePos.x == 0) {
		m_diffBetweenShapePosAndMousePos = pos - GetMousePos(window);
	}
}

FloatRect CViewShapes::ShapeEvent(Vector2f const &size, Vector2f const &pos,
	unsigned index, bool mouseClicked,
	RenderWindow &window, CommandType command)
{
	m_shapes[index]->ResetFigure(size, pos);
	if (SelectedPointForResizing(index, mouseClicked, window))
	{
		return ResizingFrameChoosenPoint(size, pos, window);
	}
	else if (ShapeShouldBeRemoved(index, command))
	{
		return RemoveShape(index);
	}
	else if (ShapeWasChoosen(m_shapes[index].get(), 
		pos, window, mouseClicked) && (!m_isFrameAction))
	{
		if (!m_pSelectedShape)
		{
			m_pSelectedShape.reset(m_shapes[index].get());
		}
		if (m_pSelectedShape == m_shapes[index])
		{
			SetDiffBetweenShapePosAndMousePos(pos, window);
			return { GetMousePos(window).x + m_diffBetweenShapePosAndMousePos.x,
				GetMousePos(window).y + m_diffBetweenShapePosAndMousePos.y, size.x, size.y };
		}
		else if (SelectedShapeIsNotSelected(index, window))
		{
			ChangeSelectedShape(index);
		}
	}
	return{ pos.x, pos.y, size.x, size.y };
}