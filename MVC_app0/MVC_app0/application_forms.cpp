#include "application_forms.h"


ApplicationForm::ApplicationForm(Vector2f const size,
				Vector2f const pos,
				String const name):
				AppObjects(size, pos, name) {
	CreateForm();
}

void ApplicationForm::SetFormPosition() {
	formRect.setPosition(pos.x, pos.y);
}

void ApplicationForm::CreateForm() {
	formRect.setSize(size);
	formRect.setFillColor(DEFAULT_FORM_COLOR);
	formRect.setOutlineColor(Color(220, 220, 220, 255));
	formRect.setOutlineThickness(GET_HALF);
	SetFormPosition();
}

void ApplicationForm::ProcessEvent(Vector2f const mousePos) {
};