#pragma once
#include "resources.h"


class Observable;
class Observer {
public:
	virtual void Update(Observable *observable, String const command) = 0;
};