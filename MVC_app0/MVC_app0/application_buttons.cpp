#include "application_buttons.h"


ApplicationButton::ApplicationButton(Vector2f const size, Vector2f const pos, String const name):
				ApplicationForm(size, pos, name),
				buttonName(name) {
	CreateForm();
	CreateText();
}


void ApplicationButton::CreateText() {
	font.loadFromFile(TEXT_FONT_PATH);
	text.setFont(font);
	text.setString(buttonName);
	text.setScale(TEXT_SCALE, TEXT_SCALE);
	text.setColor(Color::Black);
	SetTextPosition();
}


void ApplicationButton::SetTextPosition() {
	text.setPosition(pos.x + 1, pos.y + 1);
}


Vector2f ApplicationButton::GetSize() {
	return { NULL, NULL };
}
Vector2f ApplicationButton::GetPos() {
	return { NULL, NULL };
}


void ApplicationButton::ResetFrame(Vector2f const tSize, Vector2f const tPos) {
}