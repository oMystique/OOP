#pragma once
#include "triangle.h"

class Frame : public AppObjects {
public:
	Frame(Vector2f const size, Vector2f const pos, String const name);
public:
	void Draw(RenderWindow &window) override;
	void ProcessEvent(Vector2f const mousePos) override;
private:
	void CreateFrame();
	void SetFramePosition();
private:
	RectangleShape frameRect;
	CircleShape topLeftPoint;
	CircleShape topRightPoint;
	CircleShape botLeftPoint;
	CircleShape botRightPoint;
};