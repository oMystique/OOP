#pragma once
#include <list>
#include "resources.h"

class Observer;
class Observable {
public:
	Observable();
	virtual ~Observable();
	void AddObserver(Observer *observer);
	void RemoveObservers();
	void NotifyUpdate(RenderWindow &window);
private:
	vector<Observer*> observers;
	bool notify;
};