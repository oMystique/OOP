#include "domain_model.h"
#include "abstract_view.h"

CDomainModel::~CDomainModel() {
	m_figures.clear();
	delete view;
}

void CDomainModel::Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) {
	m_figures[index]->SetNewParameters(size, pos);
}

void CDomainModel::Update(Observable *observable, String const command) {
	ActionEvent(command);
}

void CDomainModel::UpdateFigures() {
	unsigned int i = 0;
	for (auto &figure : m_figures) {
		figure->NotifyUpdate(figure->GetSize(), figure->GetPos(), i);
		i++;
	}
}

void CDomainModel::ActionEvent(String const act) {
	if (act == "Create") {
		CreateNewFigure(act);
	}
	else if (act.substring(0, 6) == "Delete") {
		DeleteFigure();
	}
	else {
		UpdateFigures();
	}
}

void CDomainModel::CreateNewFigure(String const type) {
	Vector2f pos = Vector2f(DEFAULT_WINDOW_SIZE.x / GET_HALF, DEFAULT_WINDOW_SIZE.y / GET_HALF);
	shared_ptr<CLogicFigures> newObject = make_shared<CLogicFigures>(ACT_FIGURE_RECT,
										pos,
										NONE_TYPE_STRING);
	CAbstractView *aView = new CAbstractView(this);
	aView->view = view;
	newObject->AddFigureObserver(aView);
	m_figures.push_back(newObject);
}

void CDomainModel::DeleteFigure() {
	vector<shared_ptr<CLogicFigures>>::iterator it;
	for (it = m_figures.begin(); it != m_figures.end();) {
		if ((*it)->GetPos().x == NULL) {
			it = m_figures.erase(it);
			break;
		}
		else {
			++it;
		}
	}
}



