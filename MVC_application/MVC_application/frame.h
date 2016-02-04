#pragma once
#include "figures_graphic.h"

class CFrame : public CFiguresGraphic {
public:
	CFrame();
public:
	void Draw(RenderWindow &window) override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() override;
private:
	void SetFigurePosition(Vector2f const pos) override;
private:
	RectangleShape m_frameRect;
	CircleShape m_topLeftPoint;
	CircleShape m_topRightPoint;
	CircleShape m_botLeftPoint;
	CircleShape m_botRightPoint;
};