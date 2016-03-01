#pragma once
#include "rectangle.h"

class CTriangleFigure : public CShapeGraphic 
{
public:
	CTriangleFigure();
public:
	void Draw(RenderWindow &window) const override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() const override;
private:
	void SetFigurePosition(Vector2f const pos) override;
private:
	ConvexShape m_figure;
};