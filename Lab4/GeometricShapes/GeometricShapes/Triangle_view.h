#pragma once
#include "IShapeView.h"
#include "Shape.h"


class CTriangleView : public IShapeView
{
public:
	CTriangleView(Vector2f const &topVertexPos, Vector2f const &leftVertexPos
		, Vector2f const &rightVertexPos, Color const &lineColor, Color const &fillColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::ConvexShape m_triangle;
};
