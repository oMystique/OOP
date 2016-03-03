#include "shapeObservable.h"

void CShapeObservable::AddShapeObserver(IShapeObserver *observer) 
{
	m_observers.push_back(observer);
}

void CShapeObservable::NotifyShapeUpdate(Vector2f const &size,
	Vector2f const &pos, unsigned index)
{
	for (auto &obs : m_observers)
	{
		obs->Update(this, size, pos, index);
	}
}