#pragma once
#include "IShapeView.h"
#include "Shape.h"


class CRectangleView: public IShapeView
{
public:
	CRectangleView(Vector2f const &topLeftPointPos, Vector2f const &rectProportion
		, Color const &lineColor, Color const &fillColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::RectangleShape m_rect;
};
