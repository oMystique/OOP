#include "figure_observable.h"
#include "figure_observer.h"

CFigureObservable::CFigureObservable() :notify(true) {
};

CFigureObservable::~CFigureObservable() {
	RemoveFigureObservers();
	observers.clear();
}

void CFigureObservable::AddFigureObserver(CFigureObserver *observer) {
	observers.push_back(observer);
}

void CFigureObservable::RemoveFigureObservers() {
	vector<CFigureObserver*>::iterator it;
	for (it = observers.begin(); it != observers.end();) {
		CFigureObserver *b = *it;
		it = observers.erase(it);
		delete b;
	}

}

void CFigureObservable::NotifyUpdate(Vector2f const size, Vector2f const pos, unsigned int const index) {
	for (auto &observer : observers) {
		observer->Update(this, size, pos, index);
	}
}