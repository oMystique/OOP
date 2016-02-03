#include "model.h"
#include "view.h"
#include "controllers.h"

CModel::CModel(): Observable(nullptr) {
	m_isNotExit = true;
	m_view = new CView(this);
	AddObserver(m_view);
	m_domainModel = new CDomainModel();
	m_domainModel->view = m_view;
	AddObserver(m_domainModel);
	Run();
}

void CModel::Update(Observable *observable, String const command) {
	m_state = command;
	if (m_state == "Exit") {
		m_isNotExit = false;
	}
}

void CModel::Run() {
	while (m_isNotExit) {
		NotifyUpdate(m_state);
	}
}

