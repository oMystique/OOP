#include "view.h"
#include <iostream>

CView::CView(): m_mouseClicked(false), 
	m_pFrame(make_unique<CFrame>()),
	m_pWindow(make_unique<RenderWindow>(VideoMode(DEFAULT_WINDOW_SIZE.x,
	DEFAULT_WINDOW_SIZE.y),
	APPLICATION_TITLE))
{
	m_pFrame->ResetFigure({ NULL, NULL }, { NULL - FRAME_POINT_RADIUS,  NULL - FRAME_POINT_RADIUS });
	m_settings.antialiasingLevel = 8;
	CreatingApplicationWindow();
}

Vector2f GetMousePos(RenderWindow &window) 
{
	Vector2i pixelPos = Mouse::getPosition(window);
	return window.mapPixelToCoords(pixelPos);
}

void CView::ShapesDraw()
{
	for (auto it = m_shapes.begin(); it != m_shapes.end();)
	{
		if ((*it)->isDeleted)
		{
			m_shapes.erase(it);
			m_pSelectedShape.release();
			m_pFrame->ResetFigure({ NULL, NULL }, { NULL - FRAME_POINT_RADIUS,  NULL - FRAME_POINT_RADIUS });
			break;
		}
		else
		{
			(*it)->Draw(*m_pWindow);
			it++;
		}
	}
}

void CView::MainUIDraw()
{
	for (auto &element : m_interfaceElements)
	{
		element->Draw(*m_pWindow);
	}
}

void CView::MenuDraw()
{
	if (m_pMenu)
	{
		m_pMenu->DrawMenu(*m_pWindow);
	}
}

void CView::Draw() 
{
	m_pWindow->clear(Color(255, 255, 255, 255));
	MainUIDraw();
	ShapesDraw();
	MenuDraw();
	m_pFrame->Draw(*m_pWindow);
	m_pWindow->display();
}

bool CView::ButtonIsSelect(CInterfaceElement &element) const
{
	return ((element.GetRect().contains(GetMousePos(*m_pWindow))) &&
		m_mouseClicked);
}

void CView::MainUserInterfaceEvents()
{
	for (auto &element : m_interfaceElements)
	{
		element->ProcessEvent(GetMousePos(*m_pWindow));
		if (ButtonIsSelect(*element))
		{
			if (element->GetName() != MENU_BUTTON_STRING)
			{
				m_command = CreateShape;
				CreateGraphicShape(element->GetName());
			}
			else
			{
				m_pMenu = make_unique<CMenu>();
			}
			m_mouseClicked = false;
		}
	}
}

void CView::CheckButtonEvents()
{
	if (!m_pMenu)
	{
		MainUserInterfaceEvents();
	}
	else
	{
		m_pMenu->MenuEvents(GetMousePos(*m_pWindow));
	}
}

void CView::ClickingLeftButtonEvent()
{
	if (m_pMenu && !m_pMenu->GetMenuWorkSpaceRect().contains(GetMousePos(*m_pWindow)))
	{
		m_pMenu.release();
		m_pMenu = nullptr;
	}
	else if (m_pFrame->GetStartMousePos().x == NULL)
	{
		m_pFrame->SetStartMousePos(GetMousePos(*m_pWindow));
	}
	m_mouseClicked = true;
}

void CView::ReleasingLeftButtonEvent()
{
	m_mouseClicked = false;
	m_isFrameAction = false;
	m_diffBetweenShapePosAndMousePos = { NULL, NULL };
	m_pFrame->SetStartMousePos({ NULL, NULL });
}

void CView::AppPollEvent() 
{
	Event event;
	while (m_pWindow->pollEvent(event))
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
	if (m_pSelectedShape != nullptr) 
	{
		m_pFrame->ResetFigure({ m_pSelectedShape->GetRect().width, m_pSelectedShape->GetRect().height },
		{ m_pSelectedShape->GetRect().left, m_pSelectedShape->GetRect().top });
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

bool CView::ShapeWasChoosen(CShapeGraphic *figure, Vector2f const &pos) const
{
	return (figure->GetRect().contains(GetMousePos(*m_pWindow)) &&
		(m_mouseClicked) && GetIntersects(pos, figure->GetRect()));
}

FloatRect CView::ResizingFrameChoosenPoint(Vector2f const &size, Vector2f const &pos)
{
	m_isFrameAction = true;
	return { m_pFrame->FrameEvent(GetMousePos(*m_pWindow), pos, size) };
}

bool CView::SelectedPointForResizing(int const &index) const
{
	return ((m_pSelectedShape == m_shapes[index]) && (m_mouseClicked)
		&& (m_pFrame->IsAction(GetMousePos(*m_pWindow))));
}

bool CView::ShapeShouldBeRemoved(int const &index) const
{
	return ((m_command == DeleteShape) && (m_shapes[index] == m_pSelectedShape));
}

FloatRect CView::RemoveShape(int const &index)
{
	m_shapes[index]->isDeleted = true;
	return { NULL, NULL, NULL, NULL };
}

bool CView::SelectedShapeIsNotSelected(int const &index) const
{
	return (m_pSelectedShape != m_shapes[index] &&
		(!m_pSelectedShape->GetRect().contains(GetMousePos(*m_pWindow))));
}

void CView::ChangeSelectedShape(int const &index)
{
	m_pSelectedShape.release();
	m_pSelectedShape.reset(m_shapes[index].get());
}

void CView::SetDiffBetweenShapePosAndMousePos(Vector2f const &pos)
{
	if (m_diffBetweenShapePosAndMousePos.x == 0) {
		m_diffBetweenShapePosAndMousePos = pos - GetMousePos(*m_pWindow);
	}
}

FloatRect CView::ShapeEvent(Vector2f const &size,
	Vector2f const &pos, unsigned const &index)
{
	m_shapes[index]->ResetFigure(size, pos);
	if (SelectedPointForResizing(index))
	{
		SetDiffBetweenShapePosAndMousePos(pos);
		return ResizingFrameChoosenPoint(size, pos);
	}
	else if (ShapeShouldBeRemoved(index))
	{
		return RemoveShape(index);
	}
	else if (ShapeWasChoosen(m_shapes[index].get(), pos) && (!m_isFrameAction))
	{
		if (!m_pSelectedShape) 
		{
			m_pSelectedShape.reset(m_shapes[index].get());
		}
		if (m_pSelectedShape == m_shapes[index])
		{
			SetDiffBetweenShapePosAndMousePos(pos);
			return { GetMousePos(*m_pWindow).x + m_diffBetweenShapePosAndMousePos.x,
				GetMousePos(*m_pWindow).y + m_diffBetweenShapePosAndMousePos.y, size.x, size.y };
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