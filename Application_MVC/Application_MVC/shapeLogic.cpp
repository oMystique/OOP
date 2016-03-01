#include "shapeLogic.h"

CShapeLogic::CShapeLogic(Vector2f const &size, Vector2f const &pos):
	m_size(size),
	m_pos(pos)
{
}

Vector2f CShapeLogic::GetSize() const
{
	return m_size;
}

Vector2f CShapeLogic::GetPos() const
{
	return m_pos;
}

void CShapeLogic::SetNewParameters(Vector2f const size, Vector2f const pos) 
{
	m_size = size;
	m_pos = pos;
}

