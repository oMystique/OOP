#include "model.h"
#include "view.h"
#include "controllers.h"

CModel::CModel() {
	m_isNotExit = true;
	CView *view = new CView(this);
	AddObserver(view);
	CDomainModel *domainModel = new CDomainModel();
	domainModel->view = view;
	AddObserver(domainModel);
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

