#pragma once
#include "commandObservable.h"
#include "shapeObservable.h"

class CShapeLogic
{
public:
	CShapeLogic(Vector2f const &size, Vector2f const &pos);
	Vector2f GetSize() const;
	Vector2f GetPos() const;
	void SetNewParameters(Vector2f const size, Vector2f const pos);
private:
	Vector2f m_size;
	Vector2f m_pos;
};