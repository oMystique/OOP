#pragma once
#include "model.h"
#include "view.h"

class CController : public ICommandObserver, public CCommandObservable,
					public IShapeObserver, public CShapeObservable
{
public:
	void Update(CCommandObservable *observable, CommandType command) override;
	void Update(CShapeObservable *observable, Vector2f const &size, Vector2f const &pos, unsigned const &index) override;
};