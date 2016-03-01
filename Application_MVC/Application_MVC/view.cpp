#include "view.h"
#include <iostream>
CView::CView(): m_mouseClicked(false), 
	m_frame(make_unique<CFrame>()),
	m_window(make_unique<RenderWindow>(VideoMode(DEFAULT_WINDOW_SIZE.x,
	DEFAULT_WINDOW_SIZE.y),
	APPLICATION_TITLE))
{
	m_frame->ResetFigure({ NULL, NULL }, { NULL - FRAME_POINT_RADIUS,  NULL - FRAME_POINT_RADIUS });
	m_settings.antialiasingLevel = 8;
	CreatingApplicationWindow();
}

Vector2f GetMousePos(RenderWindow &window) 
{
	Vector2i pixelPos = Mouse::getPosition(window);
	return window.mapPixelToCoords(pixelPos);
}

void CView::Draw() 
{
	m_window->clear(Color(255, 255, 255, 255));
	for (auto &element : m_interfaceElements)
	{
		element->Draw(*m_window);
	}
	for (auto it = m_shapes.begin(); it != m_shapes.end();)
	{
		if ((*it)->isDeleted) 
		{
			m_shapes.erase(it);
			m_selectedShape.release();
			m_frame->ResetFigure({ NULL, NULL }, { NULL - FRAME_POINT_RADIUS,  NULL - FRAME_POINT_RADIUS });
			break;
		}
		else
		{
			(*it)->Draw(*m_window);
			it++;
		}
	}
	m_frame->Draw(*m_window);
	m_window->display();
}

bool CView::FigureButtonIsSelect(CInterfaceElement &element) const
{
	return ((element.GetRect().contains(GetMousePos(*m_window))) &&
		m_mouseClicked && (element.GetName() != MENU_BUTTON_STRING));
}

void CView::CheckButtonEvents()
{
	for (auto &element : m_interfaceElements)
	{
		element->ProcessEvent(GetMousePos(*m_window));
		if (FigureButtonIsSelect(*element))
		{
			m_command = CreateShape;
			CreateGraphicShape(element->GetName());
			m_mouseClicked = false;
			break;
		}
	}
}

void CView::ClickingLeftButtonEvent()
{
	if (m_frame->GetStartMousePos().x == NULL)
	{
		m_frame->SetStartMousePos(GetMousePos(*m_window));
	}
	m_mouseClicked = true;
}

void CView::ReleasingLeftButtonEvent()
{
	m_mouseClicked = false;
	m_isFrameAction = false;
	m_frame->SetStartMousePos({ NULL, NULL });
}

void CView::AppPollEvent() 
{
	Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_command = ExitProgram;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Delete))
		{
			m_command = DeleteShape;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			ClickingLeftButtonEvent();
		}
		else
		{
			ReleasingLeftButtonEvent();
		}
	}
}

void CView::ProcessEvent() 
{
	m_command = None;
	AppPollEvent();
	CheckButtonEvents();
	if (m_selectedShape != nullptr) 
	{
		m_frame->ResetFigure({ m_selectedShape->GetRect().width, m_selectedShape->GetRect().height },
		{ m_selectedShape->GetRect().left, m_selectedShape->GetRect().top });
	}
}

void CView::CreatingApplicationWindow() 
{
	CreateInterfaceForms();
	CreateInterfaceButtons();
}

void CView::Update(CCommandObservable *observable, CommandType command)
{
	ProcessEvent();
	Draw();
	NotifyCommandUpdate(m_command);
}

bool CView::ShapeWasChoosen(CShapeGraphic *figure) const
{
	return (figure->GetRect().contains(GetMousePos(*m_window)) &&
		(m_mouseClicked) && GetIntersects(GetMousePos(*m_window), figure->GetRect()));
}

FloatRect CView::ResizingFrameChoosenPoint(Vector2f const &size, Vector2f const &pos)
{
	m_isFrameAction = true;
	return { m_frame->FrameEvent(GetMousePos(*m_window), pos, size) };
}

bool CView::SelectedPointForResizing(int const &index) const
{
	return ((m_selectedShape == m_shapes[index]) && (m_mouseClicked)
		&& (m_frame->IsAction(GetMousePos(*m_window))));
}

bool CView::ShapeShouldBeRemoved(int const &index) const
{
	return ((m_command == DeleteShape) && (m_shapes[index] == m_selectedShape));
}

FloatRect CView::RemoveShape(int const &index)
{
	m_shapes[index]->isDeleted = true;
	return { NULL, NULL, NULL, NULL };
}

bool CView::SelectedShapeIsNotSelected(int const &index) const
{
	return (m_selectedShape != m_shapes[index] &&
		(!m_selectedShape->GetRect().contains(GetMousePos(*m_window))));
}

void CView::ChangeSelectedShape(int const &index)
{
	m_selectedShape.release();
	m_selectedShape.reset(m_shapes[index].get());
}

FloatRect CView::ShapeEvent(Vector2f const &size,
	Vector2f const &pos, unsigned const &index)
{
	m_shapes[index]->ResetFigure(size, pos); // m_index->temp avaliable
	if (SelectedPointForResizing(index))
	{
		return ResizingFrameChoosenPoint(size, pos);
	}
	else if (ShapeShouldBeRemoved(index))
	{
		return RemoveShape(index);
	}
	else if (ShapeWasChoosen(m_shapes[index].get()) && (!m_isFrameAction))
	{
		if (m_selectedShape == nullptr) 
		{
			m_selectedShape.reset(m_shapes[index].get());
		}
		if (m_selectedShape == m_shapes[index])
		{
			return { GetMousePos(*m_window).x, GetMousePos(*m_window).y, size.x, size.y };
		}
		else if (SelectedShapeIsNotSelected(index))
		{
			ChangeSelectedShape(index);
		}
	}
	return { pos.x, pos.y, size.x, size.y };
}

void CView::Update(CShapeObservable *observable, Vector2f const &size,
	Vector2f const &pos, unsigned const &index)
{
	auto rect = ShapeEvent(size, pos, index);
	NotifyShapeUpdate({ rect.left, rect.top }, { rect.width, rect.height }, index);
}