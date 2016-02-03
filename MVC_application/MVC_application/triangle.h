#pragma once
#include "rectangle.h"

class CTriangleFigure : public CFiguresGraphic {
public:
	CTriangleFigure();
public:
	void Draw(RenderWindow &window) override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() override;
private:
	void SetFigurePosition(Vector2f const pos) override;
private:
	ConvexShape m_figure;
};