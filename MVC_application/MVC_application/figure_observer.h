#pragma once
#include "resources.h"


class CFigureObservable;
class CFigureObserver {
public:
	virtual void Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) = 0;
};