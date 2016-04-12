#pragma once
#include "IShapeView.h"
#include "Shape.h"

class CLineSegmentView : public IShapeView
{
public:
	CLineSegmentView(Vector2f const &firstPointPos, Vector2f const &secondPointPos, Color const &lineColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::Vertex m_line[2];
};