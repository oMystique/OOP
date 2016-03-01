#pragma once
#include "application_forms.h"

class CApplicationButton : public CApplicationForm 
{
public:
	CApplicationButton(Vector2f const &size, Vector2f const &pos, String const &name);
public:
	void Draw(RenderWindow &window) const override;
	void ProcessEvent(Vector2f const mousePos) override;
	FloatRect GetRect() const override;
private:
	void CreateText();
	void SetTextPosition();
private:
	Font m_font;
	Text m_text;
};