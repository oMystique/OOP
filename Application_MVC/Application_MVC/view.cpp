#include "view.h"

CView::CView(): m_mouseClicked(false), 
	m_pWindow(make_unique<RenderWindow>(VideoMode(DEFAULT_WINDOW_SIZE.x,
	DEFAULT_WINDOW_SIZE.y),
	APPLICATION_TITLE))
{
	m_pFrame->ResetFigure({ OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS },
			{ OUTSTIDE_WORKSPACE_POS - FRAME_POINT_RADIUS,
			OUTSTIDE_WORKSPACE_POS - FRAME_POINT_RADIUS });
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
			m_pFrame->ResetFigure({ OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS },
					{ OUTSTIDE_WORKSPACE_POS - FRAME_POINT_RADIUS,
					OUTSTIDE_WORKSPACE_POS - FRAME_POINT_RADIUS });
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

void CView::MainUserInterfaceEvents()
{
	for (auto &element : m_interfaceElements)
	{
		element->ProcessEvent(GetMousePos(*m_pWindow));
		if (ButtonIsSelect(*element, *m_pWindow, m_mouseClicked))
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
	else if (m_pFrame->GetStartMousePos().x == OUTSTIDE_WORKSPACE_POS)
	{
		m_pFrame->SetStartMousePos(GetMousePos(*m_pWindow));
	}
	m_mouseClicked = true;
}

void CView::ReleasingLeftButtonEvent()
{
	m_mouseClicked = false;
	m_isFrameAction = false;
	m_diffBetweenShapePosAndMousePos = { OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS };
	m_pFrame->SetStartMousePos({ OUTSTIDE_WORKSPACE_POS, OUTSTIDE_WORKSPACE_POS });
}

void CView::AppPollEvent() 
{
	Event event;
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_command = ExitProgram;
			m_pSelectedShape.release();
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

void CView::Update(CCommandObservable *observable, CommandType command)
{
	ProcessEvent();
	Draw();
	NotifyCommandUpdate(m_command);
}

void CView::Update(CShapeObservable *observable, Vector2f const &size,
	Vector2f const &pos, unsigned index)
{
	auto rect = ShapeEvent(size, pos, index, m_mouseClicked, *m_pWindow, m_command);
	NotifyShapeUpdate({ rect.left, rect.top }, { rect.width, rect.height }, index);
}