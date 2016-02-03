#pragma once
#include "interface_elements.h"

class CApplicationForm : public CInterfaceElements {
public:
	CApplicationForm(Vector2f const size, Vector2f const pos, String const name);
public:
	void Draw(RenderWindow &window) const override;
	void ProcessEvent(Vector2f const mousePos) override;
protected:
	void CreateForm();
protected:
	RectangleShape m_formRect;
private:
	void SetFormPosition();
	FloatRect GetRect();
};