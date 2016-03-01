#pragma once
#include "circle.h"

class CRectangleFigure : public CShapeGraphic
{
public:
	CRectangleFigure();
public:
	void Draw(RenderWindow &window) const override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() const override;
private:
	void SetFigurePosition(Vector2f const pos) override;
private:
	RectangleShape m_figure;
};