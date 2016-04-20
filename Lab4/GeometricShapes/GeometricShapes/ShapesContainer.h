#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

class IShapeView;
typedef std::vector<std::shared_ptr<IShape>> LogicShapesPtrs;
typedef std::vector<std::shared_ptr<IShapeView>> ViewShapesPtrs;

class CShapesContainer
{
public:
	void PushPoint(Vector2f const &pos);
	void PushLineSegment(Vector2f const &firstPointPos, Vector2f const &secondPointPos, Color const &lineColor);
	void PushCircle(Vector2f const &pos, float radius, Color const &lineColor, Color const &fillColor);
	void PushRectangle(Vector2f const &topLeftPointPos, Vector2f const &rectProportion
		, Color const &lineColor, Color const &fillColor);
	void PushTriangle(Vector2f const &topVertexPos, Vector2f const &leftVertexPos
		, Vector2f const &rightVertexPos, Color const &lineColor, Color const &fillColor);
	LogicShapesPtrs GetShapes()const;
	ViewShapesPtrs GetViewShapes()const;
private:
	LogicShapesPtrs m_shapes;
	ViewShapesPtrs m_viewShapes;
};

