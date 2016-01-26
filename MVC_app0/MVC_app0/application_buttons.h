#pragma once
#include "application_forms.h"

class ApplicationButton: public ApplicationForm {
public:
	ApplicationButton(Vector2f const size, Vector2f const pos, String const name);
public:
	void Draw(RenderWindow &window) override;
	void ProcessEvent(Vector2f const mousePos) override;
private:
	void CreateText();
	void SetTextPosition();
private:
	String buttonName;
	Font font;
	Text text;
};
