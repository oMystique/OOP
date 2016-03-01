#pragma once
#include "resources.h"

class CShapeObservable;
class IShapeObserver 
{ 
public:
	virtual ~IShapeObserver() = default;
	virtual void Update(CShapeObservable *observable, Vector2f const &size,
					Vector2f const &pos, unsigned const &index) = 0;
};

