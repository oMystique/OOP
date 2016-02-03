#include "application_buttons.h"


CApplicationButton::CApplicationButton(Vector2f const size, Vector2f const pos, String const name) :
	CApplicationForm(size, pos, name) {
	CreateForm();
	CreateText();
}

void CApplicationButton::CreateText() {
	m_font.loadFromFile(TEXT_FONT_PATH);
	m_text.setFont(m_font);
	m_text.setString(m_name);
	m_text.setScale(TEXT_SCALE, TEXT_SCALE);
	m_text.setColor(Color::Black);
	SetTextPosition();
}

void CApplicationButton::SetTextPosition() {
	m_text.setPosition(m_pos.x + 1, m_pos.y + 1);
}

void CApplicationButton::Draw(RenderWindow &window) const {
	window.draw(m_formRect);
	window.draw(m_text);
}

void CApplicationButton::ProcessEvent(Vector2f const mousePos) {
	if (m_formRect.getGlobalBounds().contains(mousePos)) {
		m_formRect.setFillColor(SELECT_BUTTON_COLOR);
	}
	else {
		m_formRect.setFillColor(DEFAULT_FORM_COLOR);
	}
}

FloatRect CApplicationButton::GetRect() {
	return m_formRect.getGlobalBounds();
}