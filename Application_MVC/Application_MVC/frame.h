#pragma once
#include "triangle.h"

class CFrame : public CShapeGraphic
{
public:
	CFrame();
public:
	void Draw(RenderWindow &window) const override;
	void ResetFigure(Vector2f const size, Vector2f const pos) override;
	FloatRect GetRect() const override;
	bool IsAction(Vector2f const &mousePos) const;
	FloatRect FrameEvent(Vector2f const &mousePos, Vector2f pos, Vector2f size);
	void SetStartMousePos(Vector2f const &mousePos);
	Vector2f GetStartMousePos() const;
private:
	void SetFigurePosition(Vector2f const pos) override;
	void SetDeltaParamether(Vector2f const &mousePos);
private:
	RectangleShape m_frameRect;
	CircleShape m_topLeftPoint;
	CircleShape m_topRightPoint;
	CircleShape m_botLeftPoint;
	CircleShape m_botRightPoint;
	Vector2f m_delta;
	Vector2f m_oldMousePos;
};