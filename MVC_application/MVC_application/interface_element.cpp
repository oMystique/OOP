#include "interface_elements.h"

CInterfaceElements::CInterfaceElements(Vector2f const size,
					Vector2f const pos,
					String const name) :
	m_size(size),
	m_pos(pos),
	m_name(name) {
};

String CInterfaceElements::GetName() {
	return m_name;
}