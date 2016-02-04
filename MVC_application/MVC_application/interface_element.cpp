#include "interface_element.h"

CInterfaceElement::CInterfaceElement(Vector2f const size,
					Vector2f const pos,
					String const name) :
	m_size(size),
	m_pos(pos),
	m_name(name) {
};

String CInterfaceElement::GetName() const{
	return m_name;
}