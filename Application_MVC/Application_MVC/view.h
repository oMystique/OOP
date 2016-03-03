#pragma once
#include "viewUI.h"
#include "viewShapes.h"

class CView : public CViewUI, public CViewShapes
{
public:
	CView();
	void Update(CCommandObservable *observable, CommandType command) override;
	void Update(CShapeObservable *observable, Vector2f const &size,
		Vector2f const &pos, unsigned index) override;
private:
	void Draw();
	void ProcessEvent();
	void CheckButtonEvents();
	void AppPollEvent();
	void ClickingLeftButtonEvent();
	void ReleasingLeftButtonEvent();
	void MainUserInterfaceEvents();
	void ShapesDraw();
	void MainUIDraw();
	void MenuDraw();
private:
	unique_ptr<RenderWindow> m_pWindow = nullptr;
	ContextSettings m_settings;
	CommandType m_command;
	bool m_mouseClicked;
};
