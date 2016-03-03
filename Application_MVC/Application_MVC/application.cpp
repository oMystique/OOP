#include "application.h"

CApplication::CApplication():
	m_model(make_shared<CModel>(make_shared<CDomainModel>())),
	m_view(make_shared<CView>()),
	m_controller(make_shared<CController>())
{
	AddObservers();
	Run();
}

void CApplication::AddObservers()
{
	m_view->AddCommandObserver(m_controller.get());
	m_view->AddShapeObserver(m_controller.get());
	m_model->AddCommandObserver(m_view.get());
	m_model->AddShapeObserver(m_view.get());
	m_controller->AddCommandObserver(m_model.get());
	m_controller->AddShapeObserver(m_model.get());
}

void CApplication::Run()
{
	while (m_model->ApplicationWorks())
	{
		m_model->UpdatingModel();
	}
}