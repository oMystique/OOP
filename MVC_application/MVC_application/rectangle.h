#pragma once
#include "circle.h"

class CRectangleFigure : public CFiguresGraphic {
public:
	CRectangleFigure();
public:
	void Draw(RenderWindow &window) override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() override;
private:
	void SetFigurePosition(Vector2f const pos) override;
private:
	RectangleShape m_figure;
};