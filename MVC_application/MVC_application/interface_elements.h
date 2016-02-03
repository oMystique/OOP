#pragma once
#include "resources.h"

class CInterfaceElements {
public:
	CInterfaceElements(Vector2f const size, Vector2f const pos, String const name);
	virtual void Draw(RenderWindow &window) const = 0;
	virtual void ProcessEvent(Vector2f const mousePos) = 0;
	virtual FloatRect GetRect() = 0;
	String GetName();
protected:
	Vector2f m_size;
	Vector2f m_pos;
	String m_name;
};