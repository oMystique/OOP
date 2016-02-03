#pragma once
#include "resources.h"

class CFigureObserver;
class CFigureObservable {
public:
	CFigureObservable();
	virtual ~CFigureObservable();
	void AddFigureObserver(CFigureObserver *observer);
	void RemoveFigureObservers();
	void NotifyUpdate(Vector2f const size, Vector2f const pos, unsigned int const index);
private:
	vector<CFigureObserver*> observers;
	bool notify;
};