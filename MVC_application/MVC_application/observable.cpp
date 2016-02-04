#include "observable.h"
#include "observer.h"

Observable::Observable() :notify(true) {
};

Observable::~Observable() {
	observers.clear();
}

void Observable::AddObserver(Observer *observer) {
	observers.push_back(observer);
}

void Observable::RemoveObservers() {
	vector<Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end();) {
		Observer *b = *it;
		it = observers.erase(it);
		delete b;
	}
}

void Observable::NotifyUpdate(String const command) {
	for (auto &observer : observers) {
		observer->Update(this, command);
	}
}