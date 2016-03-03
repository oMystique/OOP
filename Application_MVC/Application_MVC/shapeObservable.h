#pragma once
#include "shapeObserver.h"

class CShapeObservable
{
public:
	virtual ~CShapeObservable() = default;
	void AddShapeObserver(IShapeObserver *observer);
	void NotifyShapeUpdate(Vector2f const &size, Vector2f const &pos, unsigned index);
private:
	vector<IShapeObserver*> m_observers;
};