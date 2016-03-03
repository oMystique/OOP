#pragma once
#include "commandObservable.h"
#include "menu.h"

class CViewUI : public ICommandObserver, public CCommandObservable
{
protected:
	void CreatingApplicationWindow();
	bool ButtonIsSelect(CInterfaceElement &element, RenderWindow &window, bool mouseClicked) const;
private:
	void CreateInterfaceForms();
	void CreateInterfaceButtons();
protected:
	vector<unique_ptr<CInterfaceElement>> m_interfaceElements;
	unique_ptr<CMenu> m_pMenu = nullptr;
};

Vector2f GetMousePos(RenderWindow &window);
