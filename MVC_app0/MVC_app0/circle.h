#pragma once
#include "application_buttons.h"

class CircleFigure : public AppObjects {
public:
	CircleFigure(Vector2f const size, Vector2f const pos, String const name);
public:
	void Draw(RenderWindow &window) override;
	void ProcessEvent(Vector2f const mousePos) override;
private:
	void CreateFigure();
	void SetFigurePosition();
private:
	CircleShape figure;
};