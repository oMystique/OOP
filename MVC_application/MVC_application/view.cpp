#include "view.h"
#include "controllers.h"
#include "figures_logic.h"
#include "domain_model.h"

CView::CView(CModel *model): Observable(model) {
	m_window = make_unique<RenderWindow>(VideoMode(DEFAULT_WINDOW_SIZE.x,
		DEFAULT_WINDOW_SIZE.y),
		APPLICATION_TITLE);
	m_frame = make_unique<CFrame>();
	m_settings.antialiasingLevel = 8;
	CBaseController *controller = new CBaseController(model);
	AddObserver(controller);
	mouseClicked = false;
	Run();
}

CView::~CView() {
	m_interfaceElements.clear();
	m_figures.clear();
}

Vector2f GetMousePos(RenderWindow &window) {
	Vector2i pixelPos = Mouse::getPosition(window);
	return window.mapPixelToCoords(pixelPos);
}

void CView::Draw() {
	m_window->clear(Color(255, 255, 255, 255));
	for (auto &element : m_interfaceElements) {
		element->Draw(*m_window);
	}
	vector<unique_ptr<CFiguresGraphic>>::iterator it;
	for (it = m_figures.begin(); it != m_figures.end();) {
		if ((*it)->isDeleted) {
			m_figures.erase(it);
			m_selectFigure.release();
			m_frame->ResetFigure({ NULL, NULL }, { NULL - GET_HALF,  NULL - GET_HALF});
			break;
		}
		else {
			(*it)->Draw(*m_window);
			it++;
		}
	}
	m_frame->Draw(*m_window);
	m_window->display();
}

void CView::CheckButtonEvents() {
	for (auto &element : m_interfaceElements) {
		element->ProcessEvent(GetMousePos(*m_window));
		if ((element->GetRect().contains(GetMousePos(*m_window))) &&
				mouseClicked && (element->GetName() != MENU_BUTTON_STRING)) {
			m_state = "Create";
			CreateGraphicFigure(element->GetName());
			mouseClicked = false;
			break;
		}
	}
}

void CView::AppPollEvent() {
	Event event;
	while (m_window->pollEvent(event)) {
		if (event.type == Event::Closed) {
			m_state = "Exit";
		}
		else if (Keyboard::isKeyPressed(Keyboard::Delete)) {
			m_state = "Delete";
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			mouseClicked = true;
		}
		else {
			mouseClicked = false;
		}
	}
}

void CView::ProcessEvent() {
	m_state = "";
	AppPollEvent();
	CheckButtonEvents();
	if (m_selectFigure != nullptr) {
		m_frame->ResetFigure({ m_selectFigure->GetRect().width, m_selectFigure->GetRect().height },
		{ m_selectFigure->GetRect().left, m_selectFigure->GetRect().top });
	}
	NotifyUpdate(m_state);
}

int CView::Run() {
	CreateInterfaceForms();
	CreateInterfaceButtons();
	return 0;
}

void CView::Update(Observable *observable, String const command) {
	ProcessEvent();
	Draw();
}

bool CView::ClickEventIsLegitimate(CFiguresGraphic *figure) {
	return (figure->GetRect().contains(GetMousePos(*m_window)) &&
		(mouseClicked) && GetIntersects(GetMousePos(*m_window), figure->GetRect()));
}

FloatRect CView::UpdateFigure(Vector2f const size, Vector2f const pos, unsigned int const index) {
	m_figures[index]->ResetFigure(size, pos);
	if ((m_state == "Delete") && (m_figures[index] == m_selectFigure)) {
		m_figures[index]->isDeleted = true;
		return { NULL, NULL, NULL, NULL };
	}
	else if (ClickEventIsLegitimate(m_figures[index].get())) {
		if (m_selectFigure == nullptr) {
			m_selectFigure.reset(m_figures[index].get());
		}
		if (m_selectFigure == m_figures[index]) {
			return { GetMousePos(*m_window).x, GetMousePos(*m_window).y, size.x, size.y };
		}
		else if (m_selectFigure != m_figures[index] && (!m_selectFigure->GetRect().contains(GetMousePos(*m_window)))) {
			m_selectFigure.release();
			m_selectFigure.reset(m_figures[index].get());
		}
	}
	return { pos.x, pos.y, size.x, size.y };
}
