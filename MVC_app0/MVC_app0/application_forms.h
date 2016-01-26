#pragma once
#include "app_objects.h"

class ApplicationForm: public AppObjects {
public:
	ApplicationForm(Vector2f const size, Vector2f const pos, String const name);
public:
	void Draw(RenderWindow &window) override;
	void ProcessEvent(Vector2f const mousePos) override;
protected:
	void CreateForm();
protected:
	RectangleShape formRect;
private:
	void SetFormPosition();
};
