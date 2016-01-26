#pragma once
#include "resources.h"
#include "app_objects.h"

class Observable;
class Observer {
public:
	virtual void Update(Observable *observable, RenderWindow &window) = 0;
};