#pragma once
#include "shapeLogic.h"

class CDomainModel 
{
public:
	vector<shared_ptr<CShapeLogic>> GetShapesArray() const;
	void CreateNewFigure();
	void DeleteFigure();
private:
	vector<shared_ptr<CShapeLogic>> m_shapes;
};