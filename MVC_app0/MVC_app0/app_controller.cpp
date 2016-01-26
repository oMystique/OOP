#include "app_controller.h"
#include "frame.h"
#include "app_model.h"

AppController::AppController(AppObjects *cObject):object(cObject) {
}

Vector2f GetMouseCoords(RenderWindow const &window) {
	Vector2i pixelPos = Mouse::getPosition(window);
	return window.mapPixelToCoords(pixelPos);
}

void AppController::Update(Observable *observable, RenderWindow &window) {
	ProcessEvent(window);
}

void AppModel::GetEvent() {
	Event event;
	mouseClicked = false;
	while (window->pollEvent(event)) {
		if (event.type == Event::Closed) {
			window->close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Delete)) {
			isObjectDelete = true;
		}
		else {
			isObjectDelete = false;
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			mouseClicked = true;
		}
		else {
			mouseClicked = false;
			isObjectSelect = false;
		}
	}
}

void AppController::ProcessEvent(RenderWindow &window) {
	object->ProcessEvent(GetMouseCoords(window));
}

