#pragma once
#include "observer.h"
#include "observable.h"
#include "application_buttons.h"
#include <memory>
#include "figures_graphic.h"
#include "frame.h"

class CModel;
class CView : public Observer, Observable {
public:
	CView(CModel *model);
	~CView();
	void Update(Observable *observable, String const command) override;
	FloatRect UpdateFigure(Vector2f size, Vector2f pos, unsigned int const index);
public:
	bool m_isFrameAction;
private:
	int Run();
	void Draw();
	void CreateInterfaceForms();
	void CreateInterfaceButtons();
	void ProcessEvent();
	void CreateGraphicFigure(String const type);
	void CheckButtonEvents();
	bool ClickEventIsLegitimate(CFiguresGraphic *figure) const;
	bool FigureButtonIsSelect(CInterfaceElement &element) const;
	void AppPollEvent();
private:
	unique_ptr<RenderWindow> m_window = nullptr;
	unique_ptr<CFiguresGraphic> m_selectFigure = nullptr;
	unique_ptr<CFrame> m_frame = nullptr;
	vector<unique_ptr<CInterfaceElement>> m_interfaceElements;
	vector<unique_ptr<CFiguresGraphic>> m_figures;
	ContextSettings m_settings;
	bool m_mouseClicked;
	String m_state;
};
