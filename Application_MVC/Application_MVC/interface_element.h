#pragma once
#include "commandObservable.h"
#include "shapeObservable.h"

class CInterfaceElement 
{
public:
	CInterfaceElement(Vector2f const &size, Vector2f const &pos, String const &name);
	virtual ~CInterfaceElement() = default;
	virtual void Draw(RenderWindow &window) const = 0;
	virtual void ProcessEvent(Vector2f const mousePos) = 0;
	virtual FloatRect GetRect() const = 0;
	String GetName() const;
protected:
	Vector2f m_size;
	Vector2f m_pos;
	String m_name;
	RectangleShape m_formRect;
};