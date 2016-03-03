#pragma once
#include "shapeObservable.h"
#include "frame.h"

class CViewShapes : public IShapeObserver, public CShapeObservable
{
protected:
	CViewShapes();
	FloatRect ShapeEvent(Vector2f const &size,
		Vector2f const &pos, unsigned index, bool mouseClicked,
		RenderWindow &window, CommandType command);
	void CreateGraphicShape(String const &type);
private:
	FloatRect ResizingFrameChoosenPoint(Vector2f const &size,
		Vector2f const &pos, RenderWindow &window);
	FloatRect RemoveShape(unsigned index);
	void ChangeSelectedShape(unsigned index);
	void SetDiffBetweenShapePosAndMousePos(Vector2f const &pos, RenderWindow &window);
	bool ShapeWasChoosen(CShapeGraphic *figure, Vector2f const &pos,
		RenderWindow &window, bool mouseClicked) const;
	bool SelectedPointForResizing(unsigned index,
		bool mouseClicked, RenderWindow &window) const;
	bool ShapeShouldBeRemoved(unsigned index, CommandType command) const;
	bool SelectedShapeIsNotSelected(unsigned index, RenderWindow &window) const;
protected:
	unique_ptr<CShapeGraphic> m_pSelectedShape = nullptr;
	unique_ptr<CFrame> m_pFrame = nullptr;
	vector<unique_ptr<CShapeGraphic>> m_shapes;
	Vector2f m_diffBetweenShapePosAndMousePos;
	bool m_isFrameAction;
};

Vector2f GetMousePos(RenderWindow &window);