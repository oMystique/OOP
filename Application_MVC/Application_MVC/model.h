#pragma once
#include "domainModel.h"

class CModel : public ICommandObserver, public CCommandObservable,
			public IShapeObserver, public CShapeObservable
{
public:
	CModel(shared_ptr<CDomainModel> domainModel);
	void Update(CCommandObservable *observable, CommandType command) override;
	void Update(CShapeObservable *observable, Vector2f const &size,
		Vector2f const &pos, unsigned index) override;
	void UpdatingModel();
	bool ApplicationWorks() const;
private:
	void UpdateShapes();
private:
	CommandType m_command;
	shared_ptr<CDomainModel> m_domainModel = nullptr;
	bool m_isNotExit;
};