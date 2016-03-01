#include "commandObservable.h"


void CCommandObservable::AddCommandObserver(ICommandObserver *observer)
{
	m_observers.push_back(observer);
}


void CCommandObservable::NotifyCommandUpdate(CommandType command)
{
	for (auto &obs : m_observers) 
	{
		obs->Update(this, command);
	}
}