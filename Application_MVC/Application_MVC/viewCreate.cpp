#include "view.h"

void CViewUI::CreateInterfaceButtons()
{
	m_interfaceElements.push_back(make_unique<CApplicationButton>(MENU_BUTTON_SIZE,
		BORDER_FORM_DEFAULT_POS,
		MENU_BUTTON_STRING));
	m_interfaceElements.push_back(make_unique<CApplicationButton>(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION),
		TRIANGLE_BUTTON_STRING));
	m_interfaceElements.push_back(make_unique<CApplicationButton>(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + FIGURE_BUTTON_RECT.x,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION),
		CIRCLE_BUTTON_STRING));
	m_interfaceElements.push_back(make_unique<CApplicationButton>(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + FIGURE_BUTTON_RECT.x * GET_HALF,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION),
		RECTANGLE_BUTTON_STRING));
}

void CViewUI::CreateInterfaceForms() 
{
	m_interfaceElements.push_back(make_unique<CApplicationForm>(MAIN_FORM_SIZE,
		MAIN_FORM_DEFAULT_POS, NONE_TYPE_STRING));
	m_interfaceElements.push_back(make_unique<CApplicationForm>(CENTER_FORM_SIZE,
		CENTER_FORM_DEFAULT_POS, NONE_TYPE_STRING));
	m_interfaceElements.push_back(make_unique<CApplicationForm>(BORDER_FORM_SIZE,
		BORDER_FORM_DEFAULT_POS, NONE_TYPE_STRING));
	m_interfaceElements.push_back(make_unique<CApplicationForm>(MENU_BUTTON_SIZE,
		BORDER_FORM_DEFAULT_POS,
		MENU_BUTTON_STRING));
}

void CViewShapes::CreateGraphicShape(String const &type)
{
	if (type == TRIANGLE_BUTTON_STRING) 
	{
		m_shapes.push_back(make_unique<CTriangleFigure>());
	}
	else if (type == CIRCLE_BUTTON_STRING)
	{
		m_shapes.push_back(make_unique<CCircleFigure>());
	}
	else if (type == RECTANGLE_BUTTON_STRING) 
	{
		m_shapes.push_back(make_unique<CRectangleFigure>());
	}
}