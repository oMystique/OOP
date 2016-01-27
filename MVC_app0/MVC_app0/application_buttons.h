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
	Vector2f GetSize() override;
	Vector2f GetPos()  override;
	void ResetFrame(Vector2f const tSize, Vector2f const tPos) override;
private:
	String buttonName;
	Font font;
	Text text;
};
