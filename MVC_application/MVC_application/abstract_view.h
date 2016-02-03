#pragma once
#include "figure_observable.h"
#include "figure_observer.h"
#include "view.h"

class CDomainModel;
class CAbstractView : public CFigureObserver, CFigureObservable {
public:
	CAbstractView(CDomainModel *domainModel);
	~CAbstractView();
	void Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) override;
	CView *view = nullptr;
};