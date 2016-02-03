#pragma once
#include "resources.h"
#include "figure_observer.h"
#include "figure_observable.h"

class CLogicFigures: public CFigureObservable {
public:
	CLogicFigures(Vector2f const size, Vector2f const pos, String const name);
	Vector2f GetSize() const;
	Vector2f GetPos() const;
	String GetName() const;
	void SetNewParameters(Vector2f const size, Vector2f const pos);
public:
	bool m_mouseClicked;
	bool m_isSelect;
	bool m_isDeleted;
private:
	Vector2f m_size;
	Vector2f m_pos;
	String m_name;
};