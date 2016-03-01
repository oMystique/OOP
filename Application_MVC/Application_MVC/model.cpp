#include "model.h"

CModel::CModel(shared_ptr<CDomainModel> domainModel) :
	m_domainModel(domainModel),
	m_isNotExit(true),
	m_command(None)
{
}

bool CModel::ApplicationWorks() const
{
	return m_isNotExit;
}

void CModel::UpdateShapes()
{
	auto shapesArray = m_domainModel->GetShapesArray();
	auto index = shapesArray.size();
	for (auto it = shapesArray.rbegin(); it != shapesArray.rend(); it++)
	{
		index--;
		NotifyShapeUpdate((*it)->GetPos(), (*it)->GetSize(), index);
	}
}

void CModel::Update(CCommandObservable *observable, CommandType command)
{
	if (command == ExitProgram)
	{
		m_isNotExit = false;
	}
	else if (command == CreateShape)
	{
		m_domainModel->CreateNewFigure();
	}
	else if (command = DeleteShape)
	{
		m_domainModel->DeleteFigure();
	}
	UpdateShapes();
}

void CModel::Update(CShapeObservable *observable, Vector2f const &size,
	Vector2f const &pos, unsigned const &index)
{
	m_domainModel->GetShapesArray()[index]->SetNewParameters(size, pos);
}

void CModel::UpdatingModel()
{
	NotifyCommandUpdate(m_command);
}