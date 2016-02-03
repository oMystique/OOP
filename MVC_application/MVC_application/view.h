#pragma once
#include "observer.h"
#include "observable.h"
#include "application_buttons.h"
#include <memory>
#include "figures_graphic.h"
#include "figure_observable.h"
#include "figure_observer.h"

class CModel;
class CDomainModel;
class CView : public Observer, Observable {
public:
	CView(CModel *model);
	~CView();
	void Update(Observable *observable, String const command) override;
	FloatRect UpdateFigure(Vector2f size, Vector2f pos, unsigned int const index);
private:
	int Run();
	void Draw() ;
	void CreateInterfaceForms();
	void CreateInterfaceButtons();
	void ProcessEvent();
	void CreateGraphicFigure(String const type);
	void CheckButtonEvents();
	bool ClickEventIsLegitimate(CFiguresGraphic *figure);
	void AppPollEvent();
private:
	unique_ptr<RenderWindow> m_window;
	vector<unique_ptr<CInterfaceElements>> m_interfaceElements;
	vector<CFiguresGraphic*> m_figures;
	CFiguresGraphic* selectFigure = nullptr;
	ContextSettings m_settings;
	bool mouseClicked;
	String m_state;
};


class CAbstractView: public CFigureObserver, CFigureObservable {
public:
	CAbstractView(CDomainModel *domainModel);
	~CAbstractView();
	void Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) override;
	CView *view = nullptr;
};