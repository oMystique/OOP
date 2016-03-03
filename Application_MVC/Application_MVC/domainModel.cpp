#include "domainModel.h"

void CDomainModel::DeleteFigure()
{
	for (auto it = m_shapes.begin(); it != m_shapes.end();)
	{
		if ((*it)->GetPos().x == OUTSTIDE_WORKSPACE_POS)
		{
			it = m_shapes.erase(it);
			break;
		}
		else 
		{
			++it;
		}
	}
}

void CDomainModel::CreateNewFigure()
{
	Vector2f pos = Vector2f(DEFAULT_WINDOW_SIZE.x / GET_HALF, DEFAULT_WINDOW_SIZE.y / GET_HALF);
	shared_ptr<CShapeLogic> newObject = make_shared<CShapeLogic>(ACT_FIGURE_RECT, pos);
	m_shapes.push_back(newObject);
}

vector<shared_ptr<CShapeLogic>> CDomainModel::GetShapesArray() const
{
	return m_shapes;
}