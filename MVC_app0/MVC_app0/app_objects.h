#pragma once
#include "observable.h"

class AppObjects: public Observable {
public:
	AppObjects(Vector2f const cSize, Vector2f const cPos, String cName);
	virtual void Draw(RenderWindow &window) = 0;
	virtual void ProcessEvent(Vector2f const mousePos) = 0;
public:
	bool mouseClicked;
	bool isSelect;
	String name;
protected:
	Vector2f pos;
	Vector2f size;
};

bool GetIntersects(Vector2f const mousePos, FloatRect const rect);