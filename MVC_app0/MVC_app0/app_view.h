#pragma once
#include "app_controller.h"

class AppView: public Observer {
public:
	AppView(AppObjects *cObject);
	void Update(Observable *observable, RenderWindow &window);
private:
	void DrawElements(Observable *observable, RenderWindow &window);
private:
	AppObjects *object;
};