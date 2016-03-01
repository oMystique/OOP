#pragma once
#include "frame.h"

class CView : public ICommandObserver, public CCommandObservable,
			public IShapeObserver, public CShapeObservable
{
public:
	CView();
	void Update(CCommandObservable *observable, CommandType command) override;
	void Update(CShapeObservable *observable, Vector2f const &size,
		Vector2f const &pos, unsigned const &index) override;
public:
	bool m_isFrameAction;
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
	bool ShapeWasChoosen(CShapeGraphic *figure) const;
	bool FigureButtonIsSelect(CInterfaceElement &element) const;
	bool SelectedPointForResizing(int const &index) const;
	bool ShapeShouldBeRemoved(int const &index) const;
	bool SelectedShapeIsNotSelected(int const &index) const;
private:
	unique_ptr<RenderWindow> m_window = nullptr;
	unique_ptr<CShapeGraphic> m_selectedShape = nullptr;
	unique_ptr<CFrame> m_frame = nullptr;
	vector<unique_ptr<CInterfaceElement>> m_interfaceElements;
	vector<unique_ptr<CShapeGraphic>> m_shapes;
	ContextSettings m_settings;
	CommandType m_command;
	bool m_mouseClicked;
};
