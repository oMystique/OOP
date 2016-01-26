#pragma once
#include "observer.h"

class AppController: public Observer {
public:
	AppController(AppObjects *cObject);
	void Update(Observable *observable, RenderWindow &window);
private:
	void ProcessEvent(RenderWindow &window);
private:
	AppObjects * object;
};