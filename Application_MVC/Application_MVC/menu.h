#pragma once
#include "application_buttons.h"


class CMenu
{
public:
	CMenu();
	void MenuEvents(Vector2f const &mousePos);
	FloatRect GetMenuWorkSpaceRect() const;
	void DrawMenu(RenderWindow &window);
private:
	void CreateMenuButtons();
private:
	vector<unique_ptr<CInterfaceElement>> m_menuElements;
};