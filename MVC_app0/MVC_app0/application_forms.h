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
	Vector2f GetSize() override;
	Vector2f GetPos()  override;
	void ResetFrame(Vector2f const tSize, Vector2f const tPos) override;
};
