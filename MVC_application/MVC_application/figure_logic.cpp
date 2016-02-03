#include "figures_logic.h"

CLogicFigures::CLogicFigures(Vector2f const size,
							Vector2f const pos,
							String const name):
							m_size(size), 																				
							m_pos(pos),																					
							m_name(name) {
	m_mouseClicked = false;
	m_isSelect = false;
	m_isDeleted = false;
}

Vector2f CLogicFigures::GetSize() const {
	return m_size;
}

Vector2f CLogicFigures::GetPos() const {
	return m_pos;
}

String CLogicFigures::GetName() const {
	return m_name;
}

void CLogicFigures::SetNewParameters(Vector2f const size, Vector2f const pos) {
	m_size = size;
	m_pos = pos;
}

