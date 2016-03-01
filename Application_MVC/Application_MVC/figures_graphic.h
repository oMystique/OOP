#pragma once
#include "application_buttons.h"

class CShapeGraphic 
{
public:
	CShapeGraphic();
public:
	virtual void Draw(RenderWindow &window) const = 0;
	virtual void ResetFigure(Vector2f const size, Vector2f const pos) = 0;
	virtual FloatRect GetRect() const = 0;
public:
	bool isDeleted;
private:
	virtual void SetFigurePosition(Vector2f const pos) = 0;
};


void FigureEvent(CShapeGraphic &object, Vector2f const &mousePos);
bool GetIntersects(Vector2f const &mousePos, FloatRect const &rect);
