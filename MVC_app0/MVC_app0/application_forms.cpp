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
	formRect.setOutlineColor(Color(220, 220, 220, 255)); //TODO: REF
	formRect.setOutlineThickness(GET_HALF);
	SetFormPosition();
}

void ApplicationForm::ProcessEvent(Vector2f const mousePos) {
};

Vector2f ApplicationForm::GetSize() {
	return { NULL, NULL };
}
Vector2f ApplicationForm::GetPos() {
	return { NULL, NULL };
}

void ApplicationForm::ResetFrame(Vector2f const tSize, Vector2f const tPos) {
}