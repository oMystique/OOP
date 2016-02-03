#pragma once
#include "resources.h"

class CFiguresGraphic {
public:
	CFiguresGraphic();
public:
	virtual void Draw(RenderWindow &window) = 0;
	virtual void ResetFigure(Vector2f const size, Vector2f const pos) = 0;
	virtual FloatRect GetRect() = 0;
public:
	bool isDeleted;
private:
	virtual void SetFigurePosition(Vector2f const pos) = 0;
};


void FigureEvent(CFiguresGraphic &object, Vector2f const mousePos);
bool GetIntersects(Vector2f const mousePos, FloatRect const rect);
