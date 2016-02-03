#pragma once
#include "observer.h"
#include "observable.h"
#include "figure_observer.h"
#include "figure_observable.h"
#include "domain_model.h"


class CBaseController : public Observer, Observable {
public:
	CBaseController(CModel *model);
	void Update(Observable *observable, String const command) override;
};

class CFigureController : public CFigureObserver, CFigureObservable {
public:
	CFigureController(CDomainModel *domainModel);
	void Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) override;
};