#pragma once
#include "triangle.h"
#include "figures_logic.h"
#include "observer.h"
#include "view.h"
#include "figure_observer.h"

class CDomainModel: public Observer, public CFigureObserver {
public:
	~CDomainModel();
	void Update(Observable *observable, String const command) override;
	void Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) override;
	void ActionEvent(String const act);
public:
	CView *view = nullptr;
private:
	void CreateNewFigure(String const type);
	void DeleteFigure();
	void UpdateFigures();
private:
	vector<shared_ptr<CLogicFigures>> m_figures;
};