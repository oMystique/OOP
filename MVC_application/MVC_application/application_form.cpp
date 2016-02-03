#include "application_forms.h"

CApplicationForm::CApplicationForm(Vector2f const size,
	Vector2f const pos,
	String const name) :
	CInterfaceElements(size, pos, name) {
	CreateForm();
}

void CApplicationForm::SetFormPosition() {
	m_formRect.setPosition(m_pos.x, m_pos.y);
}

void CApplicationForm::CreateForm() {
	m_formRect.setSize(m_size);
	m_formRect.setFillColor(DEFAULT_FORM_COLOR);
	m_formRect.setOutlineColor(DEFAULT_OUTLINE_COLOR);
	m_formRect.setOutlineThickness(GET_HALF);
	SetFormPosition();
}

void CApplicationForm::ProcessEvent(Vector2f const mousePos) {
};

void CApplicationForm::Draw(RenderWindow &window) const {
	window.draw(m_formRect);
}

FloatRect CApplicationForm::GetRect() {
	return { NULL, NULL, NULL, NULL };
}