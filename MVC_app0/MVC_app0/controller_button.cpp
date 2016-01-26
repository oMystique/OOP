#include "app_controller.h"
#include "application_buttons.h"


void ApplicationButton::ProcessEvent(Vector2f const mousePos) {
	if (formRect.getGlobalBounds().contains(mousePos)) {
		formRect.setFillColor(SELECT_BUTTON_COLOR);
		if (mouseClicked) {
			isSelect = true;
		}
		else {
			isSelect = false;
		}
	}
	else {
		formRect.setFillColor(DEFAULT_FORM_COLOR);
	}
}