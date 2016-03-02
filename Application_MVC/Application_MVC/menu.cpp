#include "menu.h"
#include <iostream>
CMenu::CMenu()
{
	CreateMenuButtons();
}

void CMenu::CreateMenuButtons()
{
	m_menuElements.push_back(make_unique<CApplicationButton>(MENU_WORKSPACE_SIZE,
		MENU_WORKSPACE_POS, NONE_TYPE_STRING));
	m_menuElements.push_back(make_unique<CApplicationButton>(MENU_SUBBUTTON_SIZE,
		MENU_WORKSPACE_POS, OPEN_FROM_STRING));
	m_menuElements.push_back(make_unique<CApplicationButton>(MENU_SUBBUTTON_SIZE,
		MENU_WORKSPACE_POS + Vector2f(0, MENU_SUBBUTTON_SIZE.y), SAVE_AS_STRING));
	m_menuElements.push_back(make_unique<CApplicationButton>(MENU_SUBBUTTON_SIZE,
		MENU_WORKSPACE_POS + Vector2f(0, MENU_SUBBUTTON_SIZE.y * 2), EXIT_STRING));
}

void CMenu::DrawMenu(RenderWindow &window)
{
	for (auto &element : m_menuElements)
	{
		element->Draw(window);
	}
}

void CMenu::MenuEvents(Vector2f const &mousePos)
{
	for (auto &element : m_menuElements)
	{
		element->ProcessEvent(mousePos);
	}
}

FloatRect CMenu::GetMenuWorkSpaceRect() const
{
	return m_menuElements[0]->GetRect();
}