#pragma once
#include "triangle.h"

class Frame : public AppObjects {
public:
	Frame(Vector2f const size, Vector2f const pos, String const name);
	~Frame();
public:
	void Draw(RenderWindow &window) override;
	void ProcessEvent(Vector2f const mousePos) override;
	void ResetFrame(Vector2f const tSize, Vector2f const tPos);
	void SetEditObject(AppObjects *&appObject);
private:
	void CreateFrame();
	void SetFramePosition();
	void SetPointsPosition();
	void SetFrameOrigin(Vector2f const mousePos);
	Vector2f GetSize() override;
	Vector2f GetPos()  override;
private:
	RectangleShape frameRect;
	CircleShape topLeftPoint;
	CircleShape topRightPoint;
	CircleShape botLeftPoint;
	CircleShape botRightPoint;
	AppObjects *appObj = nullptr;
	Vector2f temp;
};