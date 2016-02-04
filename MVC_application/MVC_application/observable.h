#pragma once
#include "resources.h"

class Observer;
class CModel;
class Observable {
public:
	Observable();
	~Observable();
	void AddObserver(Observer *observer);
	void RemoveObservers();
	void NotifyUpdate(String const command);
private:
	vector<Observer*> observers;
	bool notify;
};