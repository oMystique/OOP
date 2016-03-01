#pragma once
#include "commandObserver.h"

class CCommandObservable 
{
public:
	virtual ~CCommandObservable() = default;
	void AddCommandObserver(ICommandObserver *observer);
	void NotifyCommandUpdate(CommandType command);
private:
	vector<ICommandObserver*> m_observers;
};