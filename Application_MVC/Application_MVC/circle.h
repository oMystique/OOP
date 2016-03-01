#pragma once
#include "figures_graphic.h"

class CCircleFigure: public CShapeGraphic
{
public:
	CCircleFigure();
public:
	void Draw(RenderWindow &window) const override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() const override;
private:
	void SetFigurePosition(Vector2f const pos) override;
private:
	CircleShape m_figure;
};