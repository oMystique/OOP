#include "viewUI.h"

bool CViewUI::ButtonIsSelect(CInterfaceElement &element, RenderWindow &window, bool mouseClicked) const
{
	return ((element.GetRect().contains(GetMousePos(window))) && mouseClicked);
}

void CViewUI::CreatingApplicationWindow()
{
	CreateInterfaceForms();
	CreateInterfaceButtons();
}