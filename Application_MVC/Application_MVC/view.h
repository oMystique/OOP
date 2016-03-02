#pragma once
#include "frame.h"
#include "menu.h"

class CView : public ICommandObserver, public CCommandObservable,
			public IShapeObserver, public CShapeObservable
{
public:
	CView();
	void Update(CCommandObservable *observable, CommandType command) override;
	void Update(CShapeObservable *observable, Vector2f const &size,
		Vector2f const &pos, unsigned const &index) override;
private:
	FloatRect ShapeEvent(Vector2f const &size,
		Vector2f const &pos, unsigned const &index);
	FloatRect ResizingFrameChoosenPoint(Vector2f const &size, Vector2f const &pos);
	FloatRect RemoveShape(int const &index);
	void CreatingApplicationWindow();
	void Draw();
	void CreateInterfaceForms();
	void CreateInterfaceButtons();
	void ProcessEvent();
	void CreateGraphicShape(String const &type);
	void CheckButtonEvents();
	void AppPollEvent();
	void ClickingLeftButtonEvent();
	void ReleasingLeftButtonEvent();
	void ChangeSelectedShape(int const &index);
	void SetDiffBetweenShapePosAndMousePos(Vector2f const &pos);
	void MainUserInterfaceEvents();
	void ShapesDraw();
	void MainUIDraw();
	void MenuDraw();
	bool ShapeWasChoosen(CShapeGraphic *figure, Vector2f const &pos) const;
	bool ButtonIsSelect(CInterfaceElement &element) const;
	bool SelectedPointForResizing(int const &index) const;
	bool ShapeShouldBeRemoved(int const &index) const;
	bool SelectedShapeIsNotSelected(int const &index) const;
private:
	unique_ptr<RenderWindow> m_pWindow = nullptr;
	unique_ptr<CShapeGraphic> m_pSelectedShape = nullptr;
	unique_ptr<CFrame> m_pFrame = nullptr;
	unique_ptr<CMenu> m_pMenu = nullptr;
	vector<unique_ptr<CInterfaceElement>> m_interfaceElements;
	vector<unique_ptr<CShapeGraphic>> m_shapes;
	ContextSettings m_settings;
	CommandType m_command;
	bool m_mouseClicked;
	bool m_isFrameAction;
	Vector2f m_diffBetweenShapePosAndMousePos;
};
